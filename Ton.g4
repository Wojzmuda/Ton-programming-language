grammar Ton;

program : header* statement* EOF ; 

header : USE ID SEMI ;

block : L_BRACE statement* R_BRACE ;

statement
    : varDecl           // !make INT x <- 5;
    | trackDecl         // timeline NEW track;
    | assignment        // x <- 10;
    | ifStat            // !if < ... > { ... }
    | loopStat          // !loop < ... > { ... }
    | untilStat         // !until < ... > { ... }
    | shoutStat         // !shout "złotko" ;
    | funcDef           // !define VOID zagraj_intro <INT tempo> { ... }
    | audioOpStat       // Operacje typu: A TRASH 2:8 ;
    | saveStat          // !save t1;
    | playStat          // PLAY t1;
    | returnStat        // !out 5;
    ;

varDecl : EXCLAM_MARK MAKE type ID (ASSIGN expr)? SEMI ;

trackDecl : ID NEW TRACK ID SEMI ;

// Target żeby się dało: adresowanie wielopoziomowe: ID, ID.ID, lub ID.ID."alias"
target : ID (DOT ID (DOT STRING_VAL)?)? ;

assignment 
    : target ASSIGN expr SEMI 
    | target ADD_ASSIGN expr SEMI 
    | target SUB_ASSIGN expr SEMI
    | target MULT_ASSIGN expr SEMI
    | target DIV_ASSIGN expr SEMI
    ;

returnStat : EXCLAM_MARK OUT expr? SEMI ;

shoutStat : EXCLAM_MARK SHOUT expr SEMI ;

ifStat 
    : EXCLAM_MARK IF L_ANGLE expr R_ANGLE block 
      (EXCLAM_MARK OTHERWISE IF L_ANGLE expr R_ANGLE block)* (EXCLAM_MARK OTHERWISE block)?
    ;

loopStat 
    : EXCLAM_MARK LOOP L_ANGLE expr TIMES R_ANGLE block                                  
    | EXCLAM_MARK LOOP L_ANGLE type ID FROM expr TO expr R_ANGLE block                   
    | EXCLAM_MARK LOOP L_ANGLE type ID ASSIGN expr R_ANGLE block                         
    ;

untilStat : EXCLAM_MARK UNTIL L_ANGLE expr R_ANGLE block ;

funcDef : EXCLAM_MARK DEFINE type ID L_ANGLE (type ID (COMMA type ID)*)? R_ANGLE block ;

audioOpStat
    : SHIFT target BY expr SEMI
    | MOVE target TO expr SEMI
    | MUTE target SEMI
    | UNMUTE (target | ALL) SEMI
    | ISOLATE target SEMI
    | TRASH target SEMI
    ;

saveStat : EXCLAM_MARK SAVE expr STRING_VAL SEMI ;

playStat : PLAY target SEMI ;

type : TYPE_BOOL | TYPE_INT | TYPE_NUM | TYPE_CHAR | TYPE_STRING 
     | TYPE_NOTE | TYPE_SOUND | TYPE_VOID | TYPE_ARRAY | TYPE_INSTR 
     | TYPE_TIMELINE
     ;

expr
    : L_BRACKET (expr (COMMA expr)*)? R_BRACKET                # ArrayExpr
    | ID L_PAREN (expr (COMMA expr)*)? R_PAREN                 # FunctionCallExpr
    | ID expr expr                                             # CreateSoundExpr
    | expr (AS STRING_VAL)? AT expr                            # TrackEventExpr
    | expr L_BRACKET expr R_BRACKET                            # IndexExpr    
    | expr L_BRACKET expr COLON expr R_BRACKET                 # SliceExpr    
    | L_PAREN expr R_PAREN                                     # ParensExpr
    | (NOT_KW) expr                                            # NotExpr
    | (PLUS | MINUS) expr                                      # UnaryExpr
    | expr (MULT | DIV_OP | COLON) expr                        # MulDivExpr   
    | expr (PLUS | MINUS ) expr                                # AddSubMixExpr    // + służy teraz do miksowania
    | expr AMPERSAND expr                                      # ConcatExpr       // & służy do konkatenacji
    | expr (EQ | NEQ | L_ANGLE | R_ANGLE | L_ANGLE_EQ | R_ANGLE_EQ) expr   # RelationalExpr 
    | expr AND_OP expr                                         # AndExpr
    | expr OR_OP expr                                          # OrExpr
    | NOTE_VAL                                                 # NoteValExpr
    | INT_VAL                                                  # IntValExpr
    | NUM_VAL                                                  # NumValExpr
    | BOOL_VAL                                                 # BoolValExpr
    | CHAR_VAL                                                 # CharValExpr
    | STRING_VAL                                               # StringValExpr
    | target                                                   # TargetExpr       // Zastępuje samo ID, by wspierać np. t1.skrzypeczki
    | LENGTH target                                            # LengthOfExpr 
    | EMPTYSOUND                                               # EmptySoundExpr                           
    ;

// --- TOKENS ---

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
TYPE_TIMELINE  : 'TIMELINE' ;

MAKE           : 'make' ;
IF             : 'if' ;
OTHERWISE      : 'otherwise' ;
UNTIL          : 'until' ; 
LOOP           : 'loop' ;
DEFINE         : 'define' ;
OUT            : 'out' ; 
SHOUT          : 'shout' ;   
SAVE           : 'save' ;

// Nowe słowa kluczowe
NEW            : 'NEW' ;
TRACK          : 'TRACK' ;
AS             : 'AS' ;
AT             : 'AT' ;
SHIFT          : 'SHIFT' ;
BY             : 'BY' ;
MOVE           : 'MOVE' ;
ALL            : 'ALL' ;
ISOLATE           : 'ISOLATE' ;
LENGTH         : 'LENGTH' ;
PLAY           : 'PLAY' ;

FROM           : 'FROM' ;
TO             : 'TO' ;
TIMES          : 'TIMES' ;
USE            : 'USE' ;
TRASH          : 'TRASH' ;
MUTE           : 'MUTE' ;
UNMUTE         : 'UNMUTE' ;
DIVIDE         : 'DIVIDE' ;
EMPTYSOUND     : 'EMPTYSOUND' ;

ASSIGN         : '<-' ; 
ADD_ASSIGN     : '+<-' ;
SUB_ASSIGN     : '-<-' ;
MULT_ASSIGN    : '*<-' ;
DIV_ASSIGN     : '/<-' ; 
AND_OP         : 'AND' ; 
OR_OP          : 'OR' ;
NOT_KW         : 'NOT' ;
EQ             : '==' ;
NEQ            : '!=' ;
PLUS           : '+' ;
MINUS          : '-' ; 
MULT           : '*' ; 
DIV_OP         : '/' ;
COLON          : ':' ; 
DOT            : '.' ;
AMPERSAND      : '&' ;

L_ANGLE        : '<' ;
R_ANGLE        : '>' ;
L_ANGLE_EQ     : '<=' ;
R_ANGLE_EQ     : '>=' ;
L_BRACE        : '{' ;
R_BRACE        : '}' ;
L_BRACKET      : '[' ;
R_BRACKET      : ']' ;
L_PAREN        : '(' ;             
R_PAREN        : ')' ;
SEMI           : ';' ;
COMMA          : ',' ;
EXCLAM_MARK    : '!' ;

NOTE_VAL       : [A-G] ('#' | 'b')? [0-9] ;
INT_VAL        : [0-9]+ ;
NUM_VAL        : [0-9]+ '.' [0-9]+ ;
BOOL_VAL       : 'true' | 'false' | 'TRUE' | 'FALSE' ;
CHAR_VAL       : '\'' . '\'' ;
STRING_VAL     : '"' ~["]* '"' ;

ID             : [a-zA-Z_][a-zA-Z0-9_]* ;
WS             : [ \t\r\n]+ -> skip ;
COMMENT        : '$' ~[\r\n]* -> skip ;