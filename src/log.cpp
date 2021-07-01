/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Logging Tools
 */

#include <inttypes.h>
#include <stdio.h>

#include "log.hpp"

void log(LogLevel level, const char *message) {
	switch (level) {
		case LOG_VERBOSE: printf("VERBOSE: ");
		case LOG_INFO:    printf("INFO:    ");
		case LOG_WARNING: printf("WARNING: ");
		case LOG_ERROR:   printf("ERROR:   ");
		case LOG_FATAL:   printf("FATAL:   ");
	}
	
	printf("%s\n", message);
}
