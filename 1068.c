#include <stdio.h>
#include <string.h>
 
int main() {
    char expressao[1000 + 1];
    
    while (fgets(expressao, sizeof(expressao), stdin) && expressao[0] != '\n'){
        expressao[strcspn(expressao, "\n")] = 0;
        
        int contador = 0;
        int certo = 1;
        
        for (size_t i = 0; i < strlen(expressao); i++){
            if (expressao[i] == '('){
                contador++;
            } else if (expressao[i] == ')'){
                contador--;
                if (contador < 0){
                    certo = 0;
                    break;
                }
            }
        }
        if (contador != 0){
            certo = 0;
        }
        printf("%s\n", certo ? "correct" : "incorrect");
    }
    return 0;
}