#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ptr/ptr.h>

#include <defs.h>
#include <ints.h>
#include <lists/my_list.h>
#include <file/my_file.h>
#include <lexer/lexer.h>
#include <lexer/lexer_util.h>

i32 main(i32 argc, i8* argv[]) {

    if(argc < 2) return 1;

    string src = read_string(argv[1]);

    printf(
        "str: len %d "      endl 
        "-----------"       endl 
        "%.*s"              endl 
        "-----------"       endl, 
        src.length,
        src.length,
        src.str
    );

    printf(endl"========================"endl);
    printf("_Lexer_"endl);

    lexer_util_info();
    
    lexer_init(src);

    // lex_prnt();
    lexer_tokenize();
    lexer_token_log();

    lexer_print_tokens();

    Lexer_free();



    return 0;
}