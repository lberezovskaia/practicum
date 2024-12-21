#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFF 1024
#define SIZE 128

void func(char *command) {
    	char *commands[SIZE];
    	int num_commands = 0;
    	int pipe_fd[2];
    	int prev_fd = -1;
    	pid_t pid;
	char *token = strtok(command, "|");
	while (token) {
        	commands[num_commands++] = token;
        	token = strtok(NULL, "|");
    	}
	for (int i = 0; i < num_commands; i++) {
        	while (*commands[i] == ' ') commands[i]++;
        	char *end = commands[i] + strlen(commands[i]) - 1;
        	while (*end == ' ' && end > commands[i]) *end-- = '\0';

		if (i < num_commands - 1 && pipe(pipe_fd) == -1) {
	            	perror("error in creating pipe");
        	    	exit(EXIT_FAILURE);
        	}
		pid = fork();
        	if (pid == 0) { 
            		if (prev_fd != -1) {
                		dup2(prev_fd, STDIN_FILENO);
                		close(prev_fd);
            		}
			if (i < num_commands - 1) {
	        	        close(pipe_fd[0]); 
        	        	dup2(pipe_fd[1], STDOUT_FILENO);
                		close(pipe_fd[1]);
            		}
			char *args[SIZE];
	            	int arg_count = 0;
        	    	char *arg = strtok(commands[i], " ");
            		int input_fd = -1, output_fd = -1;
			while (arg) {
	                	if (strcmp(arg, "<") == 0) { 
        				arg = strtok(NULL, " ");
                   			input_fd = open(arg, O_RDONLY);
                    			if (input_fd < 0) {
                        			perror("error for opening file for input");
                        			exit(EXIT_FAILURE);
                    			}
				} else if (strcmp(arg, ">") == 0) { 
		                    	arg = strtok(NULL, " ");
                    			output_fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    			if (output_fd < 0) {
                        			perror("error for opening file for output");
                       				exit(EXIT_FAILURE);
                    			}
				} else if (strcmp(arg, ">>") == 0) { 
			                arg = strtok(NULL, " ");
                    			output_fd = open(arg, O_WRONLY | O_CREAT | O_APPEND, 0644);
                    			if (output_fd < 0) {
                        			perror("error for opening file for appending");
                        			exit(EXIT_FAILURE);
                    			}
				}
				else {
			               	args[arg_count++] = arg;
        			}
				arg = strtok(NULL, " ");
			}
		        args[arg_count] = NULL;
			if (input_fd != -1) {
		                dup2(input_fd, STDIN_FILENO);
        			close(input_fd);
    			}
    			if (output_fd != -1) {
        			dup2(output_fd, STDOUT_FILENO);
        			close(output_fd);
    			}

			execvp(args[0], args);
		        perror("command execution error");
    			exit(EXIT_FAILURE);
		} else if (pid > 0) {
    			if (prev_fd != -1) close(prev_fd);
			if (i < num_commands - 1) close(pipe_fd[1]);

    			prev_fd = pipe_fd[0]; 
			} else {
    				perror("process execution error");
    				exit(EXIT_FAILURE);
			}
		}
		for (int i = 0; i < num_commands; i++) {
				wait(NULL);
		}
}

int main(int argc, char *argv[]) {
    	FILE *input = stdin; 
    	char command[BUFF];
	if (argc > 1) {
        	input = fopen(argv[1], "r");
	        if (!input) {
        		perror("error opening file");
            		exit(EXIT_FAILURE);
        	}
    	}
	while (1) {
		if (input == stdin) {
	            	printf("myshell> ");
        		fflush(stdout);
        	}
		if (!fgets(command, sizeof(command), input)) {
            		break;
        	}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0) {
            		exit(0);
        	}
		func(command);
	}
    	if (input != stdin) fclose(input);
    		return 0;
}
