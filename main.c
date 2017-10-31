#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"

int i = 1;

//Criar lista Industria a partir do arquivo Industria.txt
TNoI *CriaListaIndustria()
{
    FILE* parq;
    TCadastro pregaux;
    TNoI *plista, *pnovono;
//Montando lista das Industrias:
    
    parq = fopen("Industria.txt", "r");
    if(parq==NULL)
        return NULL;
    
    plista = NULL;
    while(fscanf(parq,"%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone)>0) {
        pnovono = (TNoI *)malloc(sizeof(TNoI));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Prox = plista;
        plista = pnovono;
        i++;
    }

    return plista;
}

//Listar Conteúdo da lista Industria:
void ImprimeIndustria(TNoI *LInd){
    TNoI *plista = LInd;
    printf("                     LISTA DE INDUSTRIAS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}


//Criar lista Comercio (Dupla e Circular) a partir do arquivo Comercio.txt
TNoC *CriaListaComercio()
{
    FILE* parq;
    TCadastro pregaux;
    TNoC *plista, *pnovono;
    //Montando lista dos Comércios:
    
    parq = fopen("Comercio.txt", "r");
    if(parq==NULL)
        return NULL;
    
    plista = NULL;
    while(fscanf(parq,"%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone)>0) {
        pnovono = (TNoC *)malloc(sizeof(TNoC));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        if(plista != NULL){
            pnovono->Ant  = plista->Ant;  //Circularidade
            pnovono->Prox = plista;
            plista->Ant->Prox = pnovono;  //Circularidade
            plista->Ant   = pnovono;
        }
        else{
            pnovono->Ant  = pnovono;
            pnovono->Prox = pnovono;
        }
        plista = pnovono;
        i++;
    }
    return plista;
}


//Listar Conteúdo da lista Comercio (Dupla e Circular):
void ImprimeComercio(TNoC *LCom){
    TNoC *plista;
    printf("                     LISTA DE COMERCIOS\n");
    printf("CNPJ            Razao Social                Cidade          Telefone\n");
    if(LCom == NULL)
        return;
    plista = LCom;
    do{
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
        
    }while(plista != LCom);
}

//Listar Conteúdo da lista Comercio (Cupla e Circular) da calda para cabeça:
void ImprimeComercioInvertida(TNoC *LCom){
    TNoC *plista;
    printf("                     LISTA DE COMERCIOS INVERTIDA\n");
    printf("CNPJ            Razao Social                Cidade          Telefone\n");
    if(LCom == NULL)
        return;
    plista = LCom->Ant;
    do{
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Ant;
        
    }while(plista != LCom->Ant);
}



//Criar lista Servico (atualizando o parâmetro por referência pLSer) a partir do arquivo Servico.txt
//Deve retornar 1 caso tenha sucesso. 0 caso contrário
int CriaListaServico(TDescritorS *pLSer)
{
    FILE* parq;
    TCadastro pregaux;
    TNoS *pnovono;
    //Montando lista dos Comércios:
    
    parq = fopen("Servico.txt", "r");
    if(parq==NULL)
        return 0;
    
    
    
    while(fscanf(parq,"%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone)>0) {
        pnovono = (TNoS *)malloc(sizeof(TNoS));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Ant  = NULL;
        pnovono->Prox = pLSer->Inicio;
        if(pLSer->Tamanho > 0)
            pLSer->Inicio->Ant = pnovono;
        else {
            pLSer->Fim = pnovono;
        }
        pLSer->Inicio = pnovono;
        pLSer->Tamanho++;
        i++;
    }
    return 1;
}


//Listar Conteúdo da lista Servico:
void ImprimeServico(TDescritorS *pLSer){
    TNoS *plista = pLSer->Inicio;
    printf("                     LISTA DE SERVIÇOS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

//Listar Conteúdo da lista Servico da calda para a cabeça:
void ImprimeServicoInvertida(TDescritorS *pLSer){
    TNoS *plista = pLSer->Fim;
    printf("                     LISTA DE SERVIÇOS INVERTIDA\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Ant;
    }
}

//###################ÁREA PARA COLOCAR SUA RESPOSTA - INICIO ######################



//###################ÁREA PARA COLOCAR SUA RESPOSTA - FIM ######################


//Listar Conteúdo da lista Unificada:


//Listar Conteúdo da lista Unificada da calda para a cabeça:


//DESALOCAÇÃO DE LISTAS

TNoI *DesalocaListaSimples(TNoI *pInd){
    TNoI *paux = pInd, *pprox;
//Casos especiais: Vazia ou com apenas um nó:
    if(paux==NULL)
        return NULL;
    if(paux->Prox == NULL){
        free(paux->Dados);
        free(paux);
        return NULL;
    }
    
//Caso geral: lista com 2 ou mais nós: Desalocar da cabeça para calda:
    pprox = paux->Prox;//Fazer pprox apontar para próximo nó:
    while(pprox != NULL){
        ImprimeIndustria(paux);
//Desalocar cabeça:
        free(paux->Dados);
        free(paux);
     
        paux = pprox;
        pprox = paux->Prox;
    }
        
//Desalocar último nó restante:
    ImprimeIndustria(paux);
    free(paux->Dados);
    free(paux);
    return NULL;
}

TNoC *DesalocaListaDuplaCircular(TNoC *pCom){
    TNoC *pC = pCom, *paux, *pprox;
    //Casos especiais: Vazia ou com apenas um nó:
    if(pC==NULL)
        return NULL;
    if(pC->Prox == NULL){
        free(pC->Dados);
        free(pC);
        return NULL;
    }
    //Caso geral: lista com 2 ou mais nós: Desalocar da cabeça para calda:
    paux  = pC;
    pprox = paux->Prox;//Fazer pprox apontar para próximo nó:
    while(pprox->Prox != pprox){
        ImprimeComercio(paux);
        //Fazer pprox virar a nova cabeça da lista:
        pprox->Ant = paux->Ant;  //Manter circularidade (Ant da nova cabeça apontando para calda)
        paux->Ant->Prox = pprox; //Manter circularidade (Calda->Prox apontando para nova cabeça)
        //Desalocar atual:
        free(paux->Dados);
        free(paux);
        paux  = pprox;
        pprox = paux->Prox;
    }
    
    //Desalocar último nó restante:
    ImprimeComercio(paux);
    free(paux->Dados);
    free(paux);
    return NULL;
}

void DesalocaListaDuplaDescritor(TDescritorS *pServ){
    TNoS *pprox;
//Desalocar da cabeça para calda:
    while(pServ->Tamanho > 0){
        ImprimeServico(pServ);
        pprox = pServ->Inicio->Prox;//Fazer pprox apontar para próximo nó:
        //Desalocar cabeça:
        free(pServ->Inicio->Dados);
        free(pServ->Inicio);
        pServ->Inicio = pprox;  //Setar novo início da lista
        pServ->Tamanho--;       //Setar novo tamanho da lista

        if(pprox != NULL){
            pprox->Ant = NULL;  //Ant de Novo início deve apontar para NULL
        }
    }
    pServ->Fim = NULL;
}

void DesalocaListaDuplaDescritor2(TDescritorU *pUnica){
    TNoU *pprox;
    //Desalocar da cabeça para calda:
    while(pUnica->Tamanho > 0){
        ImprimeUnificada(pUnica);
        pprox = pUnica->Inicio->Prox;//Fazer pprox apontar para próximo nó:
        //Desalocar cabeça:
        free(pUnica->Inicio->Dados);
        free(pUnica->Inicio);
        pUnica->Inicio = pprox;  //Setar novo início da lista
        pUnica->Tamanho--;       //Setar novo tamanho da lista
        
        if(pprox != NULL){
            pprox->Ant = NULL;  //Ant de Novo início deve apontar para NULL
        }
    }
    pUnica->Fim = NULL;
}

 //Desalocar todas as listas:
void DesalocaListas(TNoI **pInd, TNoC **pCom, TDescritorS *pServ, TDescritorU *pUnica){
    printf("\n..........DESALOCANDO LISTA DE INDÚSTRIAS.......\n");
    *pInd = DesalocaListaSimples(*pInd);
    printf("\n..........DESALOCANDO LISTA DE COMÉRCIOS.......\n");
    *pCom = DesalocaListaDuplaCircular(*pCom);
    printf("\n..........DESALOCANDO LISTA DE SERVIÇOS.......\n");
    DesalocaListaDuplaDescritor(pServ);
    printf("\n..........DESALOCANDO LISTA UNIFICADA.......\n");
    DesalocaListaDuplaDescritor2(pUnica);
    printf("\n..........TODAS LISTAS DESALOCADAS.......\n");
 }


int main() {
    int continuar=1;
//Listas de entrada
    // Declaração
    TNoI *LIndustria;
    TNoC *LComercio;
    TDescritorS LServico;
    //Inicialização - listas vazias:
    LIndustria = NULL;
    LComercio = NULL;
    LServico.Fim = NULL;
    LServico.Inicio = NULL;
    LServico.Tamanho = 0;
//Lista Unificada
    // Declaração
    TDescritorU LUnica;
    //Inicialização - lista vazia:
    LUnica.Fim = NULL;
    LUnica.Inicio = NULL;
    LUnica.Tamanho = 0;
    
    
    do
    {
        printf("\n\tSecretaria da Fazenda do Distrito Federal");
        printf("\n\tSistema de Unificacao de Cadastro de Contribuintes\n\n");
        printf("1. Carregar Dados de Entrada\n");
        printf("2. Gerar Lista Unificada\n");
        printf("3. Relatorio: Industrias\n");
        printf("4. Relatorio: Comercios\n");
        printf("5. Relatorio: Comercios Invertida\n");
        printf("6. Relatorio: Servicos\n");
        printf("7. Relatorio: Servicos Invertida\n");
        printf("8. Relatorio: Lista Unificada\n");
        printf("9. Relatorio: Lista Unificada Invertida\n");
        printf("10. Apagar Listas\n");
        printf("0. Sair\n");
        
        scanf("%d", &continuar);
        system("clear");
        
        switch(continuar)
        {
            case 1:
                if((LIndustria = CriaListaIndustria()))
                    printf("Lista de Industria montada!\n");
                else{
                    printf("Erro na criacao da Lista de Industria!\n");
                    break;
                }

                if((LComercio = CriaListaComercio()))
                    printf("Lista de Comercio montada!\n");
                else{
                    printf("Erro na criacao da Lista de Comercio!\n");
                    break;
                }
                
                if(CriaListaServico(&LServico))
                    printf("Lista de Servico montada!\n");
                else{
                    printf("Erro na criacao da Lista de Servico!\n");
                }
                break;
                
            case 2:
//RETIRE O COMENTÁRIO DA LINHA ABAIXO QUANDO IMPLEMENTAR SUA SOLUÇÃO NA ÁREA ACIMA RESERVADA. 
                CriaListaUnificada(LIndustria, LComercio, &LServico, &LUnica);
                printf("Lista Unificada montada!\n");
                break;
                
            case 3:
                ImprimeIndustria(LIndustria);
                break;
                
            case 4:
                ImprimeComercio(LComercio);
                break;

            case 5:
                ImprimeComercioInvertida(LComercio);
                break;
                
            case 6:
                ImprimeServico(&LServico);
                break;
                
            case 7:
                ImprimeServicoInvertida(&LServico);
                break;

            case 8:
                ImprimeUnificada(&LUnica);
                break;
                
            case 9:
                ImprimeUnificadaInvertida(&LUnica);
                break;
                
            case 10:
                DesalocaListas(&LIndustria, &LComercio, &LServico, &LUnica);
                break;
                
            case 0:
                DesalocaListas(&LIndustria, &LComercio, &LServico, &LUnica);
                break;
                
            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
    
    return 0;
}
