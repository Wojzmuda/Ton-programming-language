grammar Ton;

program : header* statement* EOF ; 

header : USE ID SEMI ;

block : L_BRACE statement* R_BRACE ;

statement
    : varDecl           // !make INT x <- 5;
    | assignment        // x <- 10;
    | ifStat            // !if < ... > { ... }
    | loopStat          // !loop < ... > { ... }
    | untilStat         // !until < ... > { ... }
    | shoutStat         // !shout "złotko" ;
    | funcDef           // !define VOID zagraj_intro <INT tempo> { ... }
    | audioOpStat       // Operacje typu: A TRASH 2:8 ;
    | saveStat      
    ;

varDecl : MAKE type ID ASSIGN expr SEMI ;

assignment : ID ASSIGN expr SEMI ;

shoutStat : SHOUT expr SEMI ;

ifStat 
    : IF L_ANGLE expr R_ANGLE block 
      (OTHERWISE IF_PLAIN L_ANGLE expr R_ANGLE block)* (OTHERWISE block)?  
    ;

loopStat 
    : LOOP L_ANGLE expr TIMES R_ANGLE block                                  
    | LOOP L_ANGLE type ID FROM expr TO expr R_ANGLE block                   
    | LOOP L_ANGLE type ID ASSIGN expr R_ANGLE block                         
    ;

untilStat : UNTIL L_ANGLE expr R_ANGLE block ;

funcDef : DEFINE type ID L_ANGLE (type ID (COMMA type ID)*)? R_ANGLE block ;


audioOpStat
    : ID TRASH expr COLON expr SEMI
    | ID MUTE expr COLON expr SEMI
    | ID DIVIDE expr SEMI
    ;

saveStat : SAVE expr STRING_VAL SEMI ;

type : TYPE_BOOL | TYPE_INT | TYPE_NUM | TYPE_CHAR | TYPE_STRING 
     | TYPE_NOTE | TYPE_SOUND | TYPE_VOID | TYPE_ARRAY | TYPE_INSTR ;

expr
    : L_BRACKET expr (COMMA expr)* R_BRACKET                   # ArrayExpr
    

    
    | ID L_PAREN (expr (COMMA expr)*)? R_PAREN                 # FunctionCallExpr
    
  
    | ID expr expr                                             			# CreateSoundExpr
    
    | expr L_BRACKET expr R_BRACKET                            # IndexExpr    
    | expr L_BRACKET expr COLON expr R_BRACKET                 # SliceExpr    
    
    | L_PAREN expr R_PAREN                                     # ParensExpr
    
    | (NOT_KW) expr                                             # NotExpr
    
    | expr (MULT | DIV_OP | COLON) expr                        # MulDivExpr   
    | expr (PLUS | MINUS ) expr                                    # AddSubExpr   
    | expr MIXWITH expr FROM expr                              # MixWithExpr
    
    | expr (EQ | NEQ | L_ANGLE | R_ANGLE) expr                 # RelationalExpr 
    | expr AND_OP expr                                         # AndExpr
    | expr OR_OP expr                                          # OrExpr
    
    | NOTE_VAL                                                 # NoteValExpr
    | INT_VAL                                                  # IntValExpr
    | NUM_VAL                                                  # NumValExpr
    | BOOL_VAL                                                 # BoolValExpr
    | CHAR_VAL                                                 # CharValExpr
    | STRING_VAL                                               # StringValExpr
    | ID                                                       # IdExpr  
    | EMPTYSOUND                                               # EmptySoundExpr
    ;




TYPE_BOOL      : 'BOOL' ;
TYPE_INT       : 'INT' ;
TYPE_NUM       : 'NUMERICAL' ;
TYPE_CHAR      : 'CHAR' ;
TYPE_STRING    : 'STRING' ;
TYPE_NOTE      : 'NOTE'; 
TYPE_SOUND     : 'SOUND';
TYPE_VOID      : 'VOID' ;
TYPE_ARRAY     : 'ARRAY' ;
TYPE_INSTR     : 'INSTRUMENT' ;



MAKE : '!make' ;
 IF : '!if' ;
 IF_PLAIN : 'if' ;
 OTHERWISE : '!otherwise' ;
 UNTIL : '!until' ; 
LOOP : '!loop' ;
 DEFINE : '!define' ;
 OUT : '!out' ; 
SHOUT : '!shout' ;   
SAVE : '!save' ; 


FROM           : 'FROM' ;
TO             : 'TO' ;
TIMES          : 'TIMES' ;
USE            : 'USE' ;             


MIXWITH        : 'MIXWITH' ;
TRASH          : 'TRASH' ;
MUTE           : 'MUTE' ;
DIVIDE         : 'DIVIDE' ;
EMPTYSOUND     : 'EMPTYSOUND' ;      


ASSIGN : '<-' ; 
AND_OP : 'AND' ; 
OR_OP : 'OR' ;
 NOT_KW : 'NOT' ;
 EQ : '==' ; 
NEQ : '!=' ;
PLUS : '+' ;
MINUS : '-' ; 
MULT : '*' ; 
DIV_OP : '/' ;
COLON : ':' ; 

L_ANGLE        : '<' ;               
R_ANGLE        : '>' ;
L_BRACE        : '{' ;
R_BRACE        : '}' ;
L_BRACKET      : '[' ;               
R_BRACKET      : ']' ;
L_PAREN        : '(' ;             
R_PAREN        : ')' ;
SEMI           : ';' ;
COMMA          : ',' ;



NOTE_VAL       : [A-G] ('#' | 'b')? [0-9] ;  
INT_VAL        : [0-9]+ ;                    
NUM_VAL        : [0-9]+ '.' [0-9]+ ;       
BOOL_VAL       : 'true' | 'false' | 'TRUE' | 'FALSE' ; 
CHAR_VAL       : '\'' . '\'' ;    
STRING_VAL     : '"' ~["]* '"' ;

ID             : [a-zA-Z_][a-zA-Z0-9_]* ;
WS             : [ \t\r\n]+ -> skip ;
COMMENT        : '$' ~[\r\n]* -> skip ;      




