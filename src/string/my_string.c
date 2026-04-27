#include <string/my_string.h>
#include <stdlib.h>
#include <string.h>


string make_string(const i8* lit) {
    string st;
    i32 len = strlen(lit);

    st.str = (i8*)malloc(len);
    st.length = len;

    return st;
}

string copy_string(string* cf, string* sf) {
    cf->length = sf->length;
    cf->str = (i8*)malloc(cf->length);
    memcpy(cf->str, sf->str, cf->length);    
}

b8 is_string_eq(string* a, string* b) {
    return ((a->length == b->length) && memcmp(a->str, b->str, a->length) == 0); 
}