#ifndef COMPILER_HOMEWORK_ERROR_H
#define COMPILER_HOMEWORK_ERROR_H

#define LOG_ERROR(Line, Col, MSG) \
    printf("[Line:%dCol:%d][ERROR] %s\n", Line, Col, MSG); \
    exit(-1);
#endif //COMPILER_HOMEWORK_ERROR_H
