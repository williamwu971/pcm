#ifndef XIAOXIANG_H
#define XIAOXIANG_H

#define xxtrace(fmt, ...)                                           \
    do {                                                            \
        fprintf(stdout, "xiaoxiang(%s:%5d) " fmt "\n", \
                 __func__, __LINE__, ##__VA_ARGS__);       \
        fflush(stdout);                                    \
    } while (0)
    
#endif