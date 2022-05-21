#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;

struct PROCESSO {
    unsigned long long int tempo;
    unsigned long long int ciclo;

    bool operator<(const PROCESSO & b) const {
        return ciclo >= b.ciclo;
    }
};

priority_queue<PROCESSO> filaEspera;
unsigned long long int tempoAtual = 0;
unsigned long long int tempoEspera = 0;

bool comp(PROCESSO a, PROCESSO b) {
    return a.tempo == b.tempo ? a.ciclo < b.ciclo : a.tempo < b.tempo; 
}

void verificarFila() {
    while(filaEspera.size() > 0) {
        PROCESSO aux = filaEspera.top();

        filaEspera.pop();
        if(tempoAtual >= aux.tempo) {
            tempoEspera += tempoAtual - aux.tempo;
            tempoAtual += aux.ciclo;
        } else {
            tempoAtual = aux.tempo + aux.ciclo;
        }
    }
}

int main() {
    int n, i;
    unsigned long long int tempo, ciclo;

    while(cin >> n) {
        tempoAtual = 0;
        tempoEspera = 0;
        vector<PROCESSO> processos;

        while(n) {
            n--;
            cin >> tempo >> ciclo;
            PROCESSO aux;
            aux.tempo = tempo;
            aux.ciclo = ciclo;

            processos.push_back(aux);

        }

        sort(processos.begin(), processos.end(), comp);
        tempoAtual = processos[0].tempo;
        
        for(i = 0; i < processos.size(); i++) {
            if(tempoAtual >= processos[i].tempo) {
                filaEspera.push(processos[i]);
            } else {
                while(true) {
                    if(filaEspera.size() > 0) {
                        PROCESSO aux = filaEspera.top();
                        filaEspera.pop();
                        if(tempoAtual >= aux.tempo) {
                            tempoEspera += tempoAtual - aux.tempo;
                            tempoAtual += aux.ciclo;
                        } else {
                            tempoAtual = aux.tempo + aux.ciclo;
                        }
                    }
                    if(filaEspera.size() > 0) {
                        if(tempoAtual >= filaEspera.top().tempo) {
                            if(processos[i].tempo < tempoAtual + filaEspera.top().ciclo) {
                                break;
                            }
                        } else {
                            if(processos[i].tempo < filaEspera.top().ciclo + filaEspera.top().tempo) {
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
                filaEspera.push(processos[i]);
            }
        }

        verificarFila();

        cout << tempoEspera << endl;
    }
    

    return 0;
}