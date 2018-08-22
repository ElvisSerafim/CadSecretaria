/*******************************************************************************
Autor: Elvis Michael Souza Serafim
Componente Curricular: Algoritmos I
Concluido em: 12/10/2017
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/

#include <stdio.h> // Biblioteca para entrada e saída de dados //
#include <stdlib.h> // Biblioteca para alocação de memória //
#include <locale.h> // Biblioteca para a utilização do set locale //

// Função principal do programa //
int main(void)
{
    //Essa função serve para adaptar o programa a língua desejada, no caso, a lingua portuguesa //
    setlocale(LC_ALL,"Portuguese");

    // Essa são variáveis referentes ao ano de utilização do programa e ao dia mes e ano de nascimento da criança //
    int anoutili,diaDN,mesDN,anoDN;

    // A primeira variável é para guardar á opção escolhida pelo usúario e a segunda para contabilizar o total de cadastros realizados //
    int opcao = 0,criancaCad = 0;

    //Essas são variáveis para armazenar os dados cadastrais da criança //
    int microcefalia1 = 0,problemacardiaco1 = 0;
    int diabetes1 = 0,planosaude1 = 0,sexos1 = 0;
    int sexoMas = 0,sexoFem = 0,peso1 = 0;

    // Essa variável é para calcular o total das crianças que nasceram no mesmo ano de pesquisa //
    int criancaANC = 0;

    // Essas são variáveis para guardar o total das crianças com microcefalia, problema cardiaco e que não tem plano de saú´de //
    int totalmicro = 0,totalCardio = 0,totalPlano = 0,totaldiabetes = 0;

    // Essas são variáveis para cálculo das porcentagens que serão apresentadas no relatório //
    float percentmicro = 0,percentcardio = 0,percentplano = 0,percentMas = 0,percentFem = 0,percentdiabet = 0;


    printf("\t\t\t!! BEM VINDO AO CADASTRO DE CRIANÇAS !!\n\n");
    printf("Em qual ano você está utilizando o aplicativo ?\n");
    scanf("%d", &anoutili);

    // Esse laço é para sempre que o valor do ano for menor ou igual a 0, ele mostrará a mensagem "comando inválido" e pedirá novamente para digitar um valor válido //

    while(anoutili <= 0 || anoutili <= 999)
    {
        printf("COMANDO INVÁLIDO !\n\n");
        printf("Dgite Novamente qual ano você está utilizando o aplicativo\n");
        scanf("%d", &anoutili);
    }

    // Esse é o laço de repetição principal do código, ele impede que o programa feche após uma execução, saindo apenas caso o usuário digite 0 na opção do menu principal//
    do
    {

    printf("DIGITE 1 PARA CADASTRO\n");
    printf("DIGITE 2 PARA RELATÓRIO PARCIAL\n");
    printf("DIGITE 0 PARA FINALIZAR O PROGRAMA\n");
    scanf("%d", &opcao);

        // Aqui na condicional switch, estão as funções principais que a opção digitada irá executar, o cadastro, o relatório e finalizar o programa //
        switch (opcao)
        {
            // Aqui o primeiro caso do condicional, se a opção digitada for igual á 1, entrará no cadastro das crianças //
            case 1:
                printf("\t\t\tCADASTRO DE CRIANÇAS\n\n");
                printf("Digite a data de nascimento respectivamente\n");
                printf("Separando dia mes e ano com o espaço\n");
                scanf("%d %d %d", &diaDN, &mesDN, &anoDN);

                //Esse laço de repetição foi utilizado para o tratamento de erro da data de nascimento//
                while( diaDN > 31 || diaDN == 0 || mesDN > 12 || mesDN == 0 || anoDN == 0 || anoDN > anoutili || anoDN <= 999)
                {
                printf("DATA DE NASCIMENTO NÃO VÁLIDA !\n\n");
                printf("Digite novamente a data de nascimento\n");
                printf("Separando dia mes e ano com o espaço\n");
                scanf("%d %d %d", &diaDN, &mesDN, &anoDN);
                }
                //Esse laço foi utilizado para sempre que a idade da criança for maior que 12, aparecer na tela comando invalido//
                while( anoutili - anoDN > 12)
                {
                printf("IDADE NÃO VÁLIDA !\n\n");
                printf("Digite novamente a data de nascimento\n");
                scanf("%d %d %d", &diaDN, &mesDN, &anoDN);
                }
                // Essa condição foi feita para incrementar valor 1 nessa variável, caso a criança nasceu no ano de pesquisa//
                if (anoDN == anoutili)
                {
                    criancaANC++;
                }

                printf("Digite o peso da criança\n");
                scanf("%f", &peso1);

                // Esse laço é para sempre que o valor do peso for menor ou igual a 0, ele mostrará a mensagem "comando inválido" e pedirá novamente para digitar um valor válido //
                while (peso1 <= 0)
                {
                    printf("COMANDO INVÁLIDO !\n\n");
                    printf("Digite o peso da criança\n");
                    scanf("%d", &peso1);
                }


                printf("Sexo da criança ? Digite 1 para masculino e 2 para feminino\n");
                scanf("%d", &sexos1);

                // Esse laço funciona enquanto a opção digitada seja diferente de 1 ou e, aparecer a mensagem de "comando invalido" e pedirá novamente para digitar uma opçao válida//
                while(sexos1 != 1 && sexos1 != 2)
                {
                    printf("COMANDO INVÁLIDO !\n\n");
                    printf("Digite 1 para masculino e 2 para feminino\n");
                    scanf("%d", &sexos1);
                }

                //Essa condição é para caso a criança seja menino, incrementar valor 1 na variavel que guarda a quantidade de meninos//
                if (sexos1 == 1)
                {
                    sexoMas++;
                }

                //Ao contrario da anterior, irá incrementar valor 1 na variavel que guarda o quantidade de meninas//
                else if (sexos1 == 2)
                {
                    sexoFem++;
                }

                printf("A criança possui microcefalia ? Digite 1 para sim e 2 para não\n");
                scanf("%d", &microcefalia1);

                // Esse laço funciona enquanto a opção digitada seja diferente de 1 ou 2, irá mostrar a mensagem "comando invalido" e pedirá para digitar uma opção válida//
                while(microcefalia1 != 1 && microcefalia1!= 2)
                {
                    printf("COMANDO INVÁLIDO !\n\n");
                    printf("A criança possui microcefalia ? Digite 1 para sim e 2 para não\n");
                    scanf("%d", &microcefalia1);
                }
                // Essa condição é para caso a criança tenha microcefalia, incrementar valor 1 na variavel de total de crianças com microcefalia//
                 if (microcefalia1 == 1)
                {
                    totalmicro++;
                }

                printf("A criança possui problema cardíaco ? Digite 1 para sim e 2 para não\n");
                scanf("%d", &problemacardiaco1);

                 // Esse laço funciona enquanto a opção digitada seja diferente de 1 ou 2, aparecer a mensagem de comando invalido, e pedirá para digitar uma opção válida//
                while(problemacardiaco1 != 1 && problemacardiaco1 != 2)
                {
                    printf("COMANDO INVÁLIDO !\n\n");
                    printf("A criança possui problema cardíaco ? Digite 1 para sim e 2 para não\n");
                    scanf("%d", &problemacardiaco1);
                }

                //Essa condição é para caso a criança tenha problema cardiaco, incrementar 1 valor na variavel que guarda o total de crianças com problema cardiaco//
                if (problemacardiaco1 == 1)
                {
                    totalCardio++;
                }


                printf("A criança possui diabetes ? Digite 1 para sim e 2 para não\n");
                scanf("%d", &diabetes1);

                // Esse laço funciona enquanto a opção digitada seja diferente de 1 ou 2, aparecer a mensagem de "comando invalido" e pedirá novamente para digitar uma opçao válida//
                while(diabetes1 != 1 && diabetes1 != 2)
                {
                    printf("COMANDO INVÁLIDO !\n\n");
                    printf("A criança possui diabetes? Digite 1 para sim e 2 para não\n");
                    scanf("%d", &diabetes1);
                }

                //Essa condição é para caso a criança tenha dabetes, incrementar valor 1 na variavel que guarda o total de crianças com diabetes//
                if (diabetes1 == 1)
                {
                    totaldiabetes++;
                }

                printf("A criança possui plano de saúde ? Digite 1 para sim e 2 para não\n");
                scanf("%d", &planosaude1);

               // Esse laço funciona enquanto a opção digitada seja diferente de 1 ou 2, irá aparecer a mensagem de "comando invalido" e pedirá novamente para digitar uma opção válida//
               while(planosaude1 != 1 && planosaude1 != 2)
               {
                   printf("COMANDO INVÁLIDO !\n\n");
                   printf("A criança possui plano de saúde ? Digite 1 para sim e 2 para não\n");
                   scanf("%d", &planosaude1);
               }

                // Essa condição é para caso a criança tenha microcefalia, incrementar 1 na variavel de total de crianças sem plano de saúde //
                if (planosaude1 == 2)
                {
                   totalPlano++;
                }

                //Essa soma é para a cada cadastro finalizado, soma 1 na variavel de criancas cadastradas//
                criancaCad = criancaCad + 1;

                //Essa operação é utilizada para calcular o percentual de crianças com microcefalia//
                percentmicro = (totalmicro * 100)/criancaCad;

                //Essa operação é utilizada para calcular o percentual de crianças com problema cardiaco//
                percentcardio = (totalCardio * 100)/criancaCad;

                // Essa operação é utilizada para calcular o percentual de crianças com diabetes//
                percentdiabet = (totaldiabetes * 100)/criancaCad;

                //Essa operação é utilizada para calcular o percentual de crianças sem plano de saude//
                percentplano = (totalPlano * 100)/criancaCad;

                //Essa operação é utilizada para calcular o percentual de meninos//
                percentMas = (sexoMas * 100)/criancaCad;

                //Essa operação é utilizada para calcular o percentual de meninas//
                percentFem = (sexoFem * 100)/criancaCad;
                break;

            //Aqui o segundo caso da condicional switch, se a opção digitada for igual á 2, entrará no relatório, onde serão apresentadas as informações obtidas no cadastro//
             case 2:
                printf("\t\t\tRELATÓRIO PARCIAL\n\n");
                printf("Crianças cadastradas:%d \n", criancaCad);
                printf("Crianças que nasceram no ano corrente: %d\n", criancaANC);
                printf("Percentual de crianças com microcefalia: %.2f\n", percentmicro);
                printf("Percentual de crianças com problema cardíaco: %.2f\n", percentcardio);
                printf("Percentual de crianças com diabetes: %.2f\n", percentdiabet);
                printf("Percentual de crianças sem plano de saúde: %.2f\n", percentplano);
                printf("Percentual de meninos: %.2f\n", percentMas);
                printf("Percentual de meninas: %.2f\n\n", percentFem);
                break;

            // Aqui o terceiro caso da condicional, se a opção digitada for 0, ele finaliza o programa//
             case 0:
                break;

            // Aqui caso a opção inicial digitada seja diferente das disponiveis, ele printa a mensagem "comando inválido e volta ao menu principal do programa//
             default:
                printf("COMANDO INVÁLIDO !\n\n");
                break;
        }

	}while(opcao != 0);
}
