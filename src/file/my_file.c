#include <file/my_file.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string read_string(const i8* path) {
    FILE* f = fopen(path, "rb");
    if(!f) {
        fprintf(stderr, "string not found"endl);
        return (string){0};
    }
    string sf;
    
    // for f size
    fseek(f, 0, SEEK_END);
    sf.length = ftell(f); 
    fseek(f, 0, SEEK_SET);

    // str
    sf.str = (i8*)malloc(sf.length);
    
    if(!sf.str) {
        fprintf(stderr, "out of memory"endl);
        fclose(f);
        return (string){0};
    }
    
    sf.length = fread(sf.str, 1, sf.length, f);

    fclose(f);

    return sf;
}
