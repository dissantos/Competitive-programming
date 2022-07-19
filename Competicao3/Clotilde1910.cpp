/*
 * ALunos: Diego Santos
 * Silvia Fonseca
 */
#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct operacao
{
    char op;
    int qtd_op;
    int valor;
};

int D;

int main()
{
    int O;
    int K;

    cin >> O >> D >> K;
    while (O != 0 || D != 0 || K != 0)
    {
        vector<int> banidos(100001);
        vector<int> valores_encontrados(100001);
        queue<operacao> fila_op;
        int canal;
        for (int i = 0; i < K; i++)
        {
            cin >> canal;
            banidos[canal] = 1;
        }
        if (O == D)
        {
            cout << "0" << endl;
        }
        else
        {
            operacao canalAtual;
            canalAtual.qtd_op = 0;
            canalAtual.valor = O;

            fila_op.push(canalAtual);
            operacao op_atual;
            bool encontrouCanal = false;
            int cont = 0;
            while (fila_op.size() > 0)
            {
                op_atual = fila_op.front();
                fila_op.pop();
                cont++;
                // cout << op_atual.valor << endl;

                if (banidos[op_atual.valor] == 0 && op_atual.valor > 0 && op_atual.valor <= 100000)
                {
                    if (op_atual.valor + 1 <= 100000)
                    {
                        if (!banidos[op_atual.valor + 1] && !valores_encontrados[op_atual.valor + 1])
                        {
                            if (op_atual.valor + 1 == D)
                            {
                                cout << op_atual.qtd_op + 1 << endl;
                                encontrouCanal = true;
                                break;
                            }
                            operacao op;
                            op.valor = op_atual.valor + 1;
                            op.qtd_op = op_atual.qtd_op + 1;
                            valores_encontrados[op_atual.valor + 1] = op_atual.qtd_op + 1;
                            fila_op.push(op);
                        }
                    }
                    if (op_atual.valor - 1 > 0)
                    {
                        if (!banidos[op_atual.valor - 1] && !valores_encontrados[op_atual.valor - 1])
                        {
                            if (op_atual.valor - 1 == D)
                            {
                                cout << op_atual.qtd_op + 1 << endl;
                                encontrouCanal = true;
                                break;
                            }
                            operacao op;
                            op.valor = op_atual.valor - 1;
                            op.qtd_op = op_atual.qtd_op + 1;
                            valores_encontrados[op_atual.valor - 1] = op_atual.qtd_op + 1;
                            fila_op.push(op);
                        }
                    }
                    if (op_atual.valor * 2 <= 100000)
                    {
                        if (!banidos[op_atual.valor * 2] && !valores_encontrados[op_atual.valor * 2])
                        {
                            if (op_atual.valor * 2 == D)
                            {
                                cout << op_atual.qtd_op + 1 << endl;
                                encontrouCanal = true;
                                break;
                            }
                            operacao op;
                            op.valor = op_atual.valor * 2;
                            op.qtd_op = op_atual.qtd_op + 1;
                            valores_encontrados[op_atual.valor * 2] = op_atual.qtd_op + 1;
                            fila_op.push(op);
                        }
                    }
                    if (op_atual.valor * 3 <= 100000)
                    {
                        if (!banidos[op_atual.valor * 3] && !valores_encontrados[op_atual.valor * 3])
                        {
                            if (op_atual.valor * 3 == D)
                            {
                                cout << op_atual.qtd_op + 1 << endl;
                                encontrouCanal = true;
                                break;
                            }
                            operacao op;
                            op.valor = op_atual.valor * 3;
                            op.qtd_op = op_atual.qtd_op + 1;
                            valores_encontrados[op_atual.valor * 3] = op_atual.qtd_op + 1;
                            fila_op.push(op);
                        }
                    }
                    if (op_atual.valor % 2 == 0 && op_atual.valor / 2 > 0)
                    {
                        if (!banidos[op_atual.valor / 2] && !valores_encontrados[op_atual.valor / 2])
                        {
                            if (op_atual.valor / 2 == D)
                            {
                                cout << op_atual.qtd_op + 1 << endl;
                                encontrouCanal = true;
                                break;
                            }
                            operacao op;
                            op.valor = op_atual.valor / 2;
                            op.qtd_op = op_atual.qtd_op + 1;
                            valores_encontrados[op_atual.valor / 2] = op_atual.qtd_op + 1;
                            fila_op.push(op);
                        }
                    }
                }
            }
            if (!encontrouCanal)
                cout << "-1" << endl;
        }

        cin >> O >> D >> K;
    }
}