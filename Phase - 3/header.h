typedef enum { typeCon, typeId, typeOpr } nodeEnum;

typedef struct {
    int value;                 
} conNodeType;


typedef struct {
    char *str;                      
} idNodeType;


typedef struct {
    int oper;                   
    int nops;                   
    struct nodeTypeTag *op[1];  
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              

    union {
        conNodeType con;        
        idNodeType id;         
        oprNodeType opr;        
    };
} nodeType;