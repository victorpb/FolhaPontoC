#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float MatrizFunc[10][6];
//FUNÇÕES DE CALCULOS

    //RECEITAS
float CalcAnuenio(float SalarioBruto, float AnosTrabalhados){
    float PercentAnuenio;
    if (AnosTrabalhados < 3){
        PercentAnuenio = 0;
    }
    else if ((AnosTrabalhados >= 3) && (AnosTrabalhados <=9)){
        int AnosTrabalhadosInt = (int)AnosTrabalhados;
        PercentAnuenio = (AnosTrabalhadosInt/3)*0.15;
    }
    else{
        PercentAnuenio = 0.20;
    };

    return SalarioBruto*PercentAnuenio;
}

float CalcGratifacao(float SalarioBruto){
    return SalarioBruto*0.15;
}

float CalcRendimento(float SalarioBruto, float AnosTrabalhados){

    float rendi, grati,anue = 0;

	grati = CalcGratifacao(SalarioBruto);

    anue = CalcAnuenio(SalarioBruto, AnosTrabalhados);


    rendi = SalarioBruto + grati + anue;

    return rendi;
}
    //END RECEITAS

    // DESPESAS

float CalcValeTransporte(float SalarioBruto){

    return SalarioBruto*0.06;
}

float CalcValInss(float Rendimento){

    if (Rendimento <= 1200.00){
        return Rendimento*0.085;
    }
    else{
        return Rendimento*0.11;
    }
}

float CalcValIrrf(float Rendimento){

    if(Rendimento > 1700.00){
        return Rendimento*0.15;
    }
    else{
        return 0;
    }
}

float CalcDespesas(float Rendimento, float SalarioBruto){

    float ValeTrans, ValInss, ValIrrf, despesas;

    ValeTrans = CalcValeTransporte(SalarioBruto);

    ValInss = CalcValInss(Rendimento);

    ValIrrf = CalcValIrrf(Rendimento);


    despesas = ValeTrans + ValInss + ValIrrf;


    return despesas;

}
    //END DESPESAS


//END FUNÇÕES DE CALCULOS
//FUNÇÕES DE AÇOES

void ImprimeFolhaPagamento(int linha){
    float salarioBruto, anosTrabalhados, despesas, receitas, salarioLiquido;

    salarioBruto = MatrizFunc[linha][1];
    anosTrabalhados = MatrizFunc[linha][2];
    despesas = MatrizFunc[linha][4];
    receitas = MatrizFunc[linha][3];
    salarioLiquido = MatrizFunc[linha][5];

    printf("*------FOLHA PAGAMENTO------*\n");
    printf("Matricula: %.0f \n", MatrizFunc[linha][0]);
    printf("Tempo de Empresa: %.2f ", anosTrabalhados);
    printf("\n");
    printf("\n");

    printf("- RECEITAS \n");
    printf("\n");
    printf("Salario Bruto: %f\n", salarioBruto );
    printf("Gratificao: %f\n", CalcGratifacao(salarioBruto));
    printf("Anuenio: %f\n", CalcAnuenio(salarioBruto,anosTrabalhados));
    printf("--Total Receitas: %f \n", receitas);

    printf("\n");

    printf("- DESPESAS \n");
    printf("\n");
    printf("Vale Transporte: %f \n", CalcValeTransporte(salarioBruto));
    printf("INSS: %f \n", CalcValInss(receitas));
    printf("IRRF: %f \n", CalcValIrrf(receitas));
    printf("--Total Despesas: %f \n", despesas);

    printf("\n");
    printf("\n");

    printf("SALARIO LIQUIDO: %f \n",  salarioLiquido);
}

void matriz(){
	int k,coluna;
	for(k=0;k<11;k++){
		for (coluna=0;coluna<6;coluna++){
			MatrizFunc[k][coluna]=-1;
		}
	}
}
void MenuPrincipal(){
printf("\n\t*****FOLHA DE PAGAMENTO***** \n");
printf("\n\t1----INCLUIR FUNCIONÁRIO");
printf("\n\t2----ALTERAR FUNCIONÁRIO");
printf("\n\t3----EXCLUIR FUNCIONÁRIO");
printf("\n\t4----FOLHA DE PAGAMENTO");
printf("\n\t5----MAIOR SALÁRIO LÍQUIDO");
printf("\n\t6----MENOR SALÁRIO LÍQUIDO");
printf("\n\t0----SAIR DO SISTEMA \n\t");
}
void IncluirFuncionario(){
    float rendimento=0, despesa=0, salarioLiquido =0, salarioBruto, anosTrabalhados;
    int linha, coluna, LimFun=0;
    float numeroMatricula;
	for(linha=0;linha<10;linha++){
		if(MatrizFunc[linha][0]==-1){
			printf("\n\tInforme o número de matrícula: ");
			scanf("\t%f", &numeroMatricula);

			printf("\n\tInforme o Salário Bruto: ");
			scanf("\t%f", &salarioBruto);

			printf("\n\tInforme o Tempo de trabalho (em anos): ");
			scanf("\t%f", &anosTrabalhados);
            printf("anos trabalhados %f", anosTrabalhados);
			rendimento = CalcRendimento(salarioBruto,anosTrabalhados);

            despesa = CalcDespesas(rendimento, salarioBruto);
            printf("despesas: %f", despesa);
            salarioLiquido = rendimento - despesa;

            MatrizFunc[linha][0] = numeroMatricula;
            MatrizFunc[linha][1] = salarioBruto;
            MatrizFunc[linha][2] = anosTrabalhados;
            MatrizFunc[linha][3] = rendimento;
            MatrizFunc[linha][4] = despesa;
            MatrizFunc[linha][5] = salarioLiquido;
			LimFun=1;
        	break;
		}
	}

	if(LimFun==1){ printf("\n\tFUNCIONÁRIO CADASTRADO COM SUCESSO!\n\t");
	}
	if(LimFun==0){ printf("\n\nLIMITE DE CADASTROS ATINGIDO!\n\n\t");
	};
}

void AlterarFuncionario(){
    float rendimento=0, despesa=0, salarioLiquido =0, salarioBruto, anosTrabalhados, matricula;
    int linha;
    printf("\n\tInforme o número de matrícula: ");
    scanf("\t%d",&matricula);
        for(linha=0;linha<5;linha++){
               if(matricula==(MatrizFunc[linha][0])) {
                    printf("\n\tInforme o Salário Bruto: ");
                    scanf("\t%f", &salarioBruto);

                    printf("\n\tInforme o Tempo de trabalho (em anos): ");
                    scanf("\t%f", &anosTrabalhados);

                    rendimento = CalcRendimento(salarioBruto,anosTrabalhados);

                    despesa = CalcDespesas(rendimento, salarioBruto);

                    salarioLiquido = rendimento - despesa;

                    MatrizFunc[linha][1] = salarioBruto;
                    MatrizFunc[linha][2] = anosTrabalhados;
                    MatrizFunc[linha][3] = rendimento;
                    MatrizFunc[linha][4] = despesa;
                    MatrizFunc[linha][5] = salarioLiquido;
                    break;
                 }

           else {
                printf("\tMATRÍCULA INVÁLIDA, TENTE NOVAMENTE!\n\t");

                }

        }
}

void ExcluirFuncionario(){
	int linha, matricula, LimFun=0;
	printf("\nInforme o número da matrícula: ");
	scanf("\t%f",&matricula);

	for(linha=0;linha<10;linha++){
		if(MatrizFunc[linha][0]==matricula){
			MatrizFunc[linha][0]=-1;
			LimFun=1;
			break;
		}
	}
	if(LimFun==0) printf("\n\tMATRÍCULA NÃO CADASTRADA, TENTE NOVAMENTE!\n\t");
	if(LimFun==1) printf("\n\tREMOVIDO COM SUCESSO!\n\t");
}


void FolhaDePagamento(){
	int linha, Teste=0;
	float matricula;
	printf("\nInforme o número da matrícula ou digite -2 para exibir a folha de todos os funcionarios: ");
	scanf("\t%f",&matricula);
	printf("Matricula: %f", matricula);
	if (matricula != -2){
        for(linha=0;linha<10;linha++){

            if(MatrizFunc[linha][0]==matricula){
                printf("linha %d", linha);
                ImprimeFolhaPagamento(linha);
                Teste=1;
                break;
            }
        }
    }
    else{
          for(linha=0;linha<10;linha++){

            if(MatrizFunc[linha][0]!=-1){
                printf("linha %d", linha);
                ImprimeFolhaPagamento(linha);
                Teste=1;
            }
        }
    }
	if(Teste==0) printf("\n\tNÃO HÁ DADOS ARMAZENADOS, NENHUM FUNCIONÁRIO CADASTRADO!\n\t");
}
void MaiorSalarioLiquido(){
	float MaiorSalario = -1;
	int linha, linhaPrint;
	linhaPrint = -1;
	for(linha=0;linha<10;linha++){

            if(MatrizFunc[linha][5] > MaiorSalario){
                linhaPrint = linha;
                MaiorSalario = MatrizFunc[linha][5];
            }
        }
    if (linhaPrint != -1){
    	ImprimeFolhaPagamento(linhaPrint);
    }

}
void MenorSalarioLiquido(){
    float MenorSalario = 9999999999999.98;
	int linha, linhaPrint;
	linhaPrint = -1;
	for(linha=0;linha<10;linha++){
            if (MatrizFunc[linha][5] != -1){

            if(MatrizFunc[linha][5] < MenorSalario){
                linhaPrint = linha;
                MenorSalario = MatrizFunc[linha][5];
            }
        }
	}
    if (linhaPrint != -1){
    	ImprimeFolhaPagamento(linhaPrint);
    }
}


int main(){
	matriz();
	int opcao=-1;
	setlocale(LC_ALL, "Portuguese");
	while(opcao!=0){
		MenuPrincipal();
		scanf("\t%d", &opcao);
		switch(opcao){
		case 1:
			IncluirFuncionario();
			system("pause");
			system("cls");
			break;
		case 2:
			AlterarFuncionario();
			system("pause");
			break;
		case 3:
			ExcluirFuncionario();
			system("pause");
			system("cls");
			break;
		case 4:
			FolhaDePagamento();
			system("pause");
			system("cls");
			break;
		case 5:
			MaiorSalarioLiquido();
			system("pause");
			system("cls");
			break;
		case 6:
			MenorSalarioLiquido();
			system("pause");
			system("cls");
			break;
		case 0:
			printf("\n\tFINALIZANDO O SISTEMA...\t");
			break;
		default:
			printf("\n\tOPÇÃO INVÁLIDA!\n\t");
			system("pause");
			system("cls");
			break;
		}
	}

return 0; }
