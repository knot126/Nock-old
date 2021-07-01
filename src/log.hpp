/*
 * Copyright (C) 2021 Decent Games
 * ===============================
 * 
 * Logging Tools
 */ 

#pragma once

enum LogLevel : signed char {
	LOG_VERBOSE = -1,
	LOG_INFO = 0,
	LOG_WARNING = 1,
	LOG_ERROR = 2,
	LOG_FATAL = 3,
};

void log(LogLevel level, const char *message);
