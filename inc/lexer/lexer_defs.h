/*
 * Copyright 2026 Jas2365
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
 * OR CONDITIONS OF ANY KIND, either express or implied.
 */


#pragma once

// char flags
#define char_space   (1 << 0) // ' ', '\r', '\t'
#define char_newline (1 << 1) // '\n'
#define char_slash   (1 << 2) // '/'
#define char_alpha   (1 << 3) //  A-Z a-z 
#define char_digit   (1 << 4) //  0-9
#define char_symbol  (1 << 5) //  + - *
#define char_tick    (1 << 6) // '
#define char_string  (1 << 7) // string ""
#define char_escape  (1 << 8) // '\\'

#define char_is(c, flag) (char_class[(u16)(c)] & (flag))

#define char_sp         ( ' '  )
#define char_tab        ( '\t' )
#define char_cr         ( '\r' )
#define char_nl         ( '\n' )
#define char_sl         ( '/'  )
#define char_es         ( '\\'  )

#define char_parenl     ( '(' )
#define char_parenr     ( ')' )
#define char_bracesl    ( '{' )
#define char_bracesr    ( '}' )
#define char_bracketl   ( '[' )
#define char_bracketr   ( ']' )
#define char_dot        ( '.' )
#define char_comma      ( ',' )
#define char_colon      ( ':' )
#define char_semicolon  ( ';' )
#define char_plus       ( '+' )
#define char_minus      ( '-' )
#define char_star       ( '*' )
#define char_percent    ( '%' )
#define char_tilde      ( '~' )
#define char_caret      ( '^' )

#define char_a ( 'a' )
#define char_b ( 'b' )
#define char_c ( 'c' )
#define char_d ( 'd' )
#define char_e ( 'e' )
#define char_f ( 'f' )
#define char_g ( 'g' )
#define char_h ( 'h' )
#define char_i ( 'i' )
#define char_j ( 'j' )
#define char_k ( 'k' )
#define char_l ( 'l' )
#define char_m ( 'm' )
#define char_n ( 'n' )
#define char_o ( 'o' )
#define char_p ( 'p' )
#define char_q ( 'q' )
#define char_r ( 'r' )
#define char_s ( 's' )
#define char_t ( 't' )
#define char_u ( 'u' )
#define char_v ( 'v' )
#define char_w ( 'w' )
#define char_x ( 'x' )
#define char_y ( 'y' )
#define char_z ( 'z' )

#define char_A ( 'A' )
#define char_B ( 'B' )
#define char_C ( 'C' )
#define char_D ( 'D' )
#define char_E ( 'E' )
#define char_F ( 'F' )
#define char_G ( 'G' )
#define char_H ( 'H' )
#define char_I ( 'I' )
#define char_J ( 'J' )
#define char_K ( 'K' )
#define char_L ( 'L' )
#define char_M ( 'M' )
#define char_N ( 'N' )
#define char_O ( 'O' )
#define char_P ( 'P' )
#define char_Q ( 'Q' )
#define char_R ( 'R' )
#define char_S ( 'S' )
#define char_T ( 'T' )
#define char_U ( 'U' )
#define char_V ( 'V' )
#define char_W ( 'W' )
#define char_X ( 'X' )
#define char_Y ( 'Y' )
#define char_Z ( 'Z' )

// underscore
#define char_us ( '_' )

#define char_0 ( '0' )
#define char_1 ( '1' )
#define char_2 ( '2' )
#define char_3 ( '3' )
#define char_4 ( '4' )
#define char_5 ( '5' )
#define char_6 ( '6' )
#define char_7 ( '7' )
#define char_8 ( '8' )
#define char_9 ( '9' )

#define char_eq   ( '=' )
#define char_bang ( '!' )
#define char_lt   ( '<' )
#define char_gt   ( '>' )
#define char_amp  ( '&' )
#define char_pipe ( '|' )

#define char_dquote ( '"' )
#define char_quote  ( '\'' )