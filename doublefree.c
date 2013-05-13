void* malloc(int i) { return ((void*)0); }
void* xmalloc(int i) { return ((void*)0); }
void free(void* p) { }

int alternative() {
    int* a = malloc(2);
#ifdef A
    free(a);
#endif
#ifdef B
    free(a);
#endif
    return 0;
}

int shadowing() {
    int* a = malloc(2);
    if (a) {
        int* a = malloc(3);
        free(a);
    }
    free(a);
    return 0;
}

int variable_shadowing() {
    int* a = malloc(2);
    if (a) {
#ifdef A
        int* a = malloc(3);
#endif
        free(a);
    }
    free(a);
    return 0;
}

void doublefree() {
    int* a = malloc(2);
    free(a);
    free(a);
}

void doublefreeif() {
    int b;
    if (b) {
        int* a = malloc(2);
        free(a);
    }
}

int test() {
    int fd;

    if (fd >= 0) {
        int *md5line;
        int *buf;

        buf = xmalloc(4096);
        free(buf);
        free(md5line);
    }
    return 0;
}


int main() {
    return 0;
}
