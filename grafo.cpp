#include <bits/stdc++.h>

using namespace std;

#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0);                                                                \
    cout.tie(0);

#define endl '\n'

#define pb push_back

map<char, set<char> > grafo;

map<char, set<char> > grafo_inverso;

vector< set<char> > all_componentes;

void imprime_set(const set<char> &dados);

set<char> intersecao_sets(set<char> s1, set<char> s2) {
    set<char> novo_set;

    for (auto value : s1) {
        if (s2.find(value) != s2.end()) {
            novo_set.insert(value);
        }
    }

    return novo_set;
}

vector<char> pegar_todos_vertices_grafo() {
    vector<char> all_vertices;
    
    set<char> mapa;

    for (auto par : grafo) {
        all_vertices.pb(par.first);
        mapa.insert(par.first);
    }

    for (auto par : grafo_inverso) {
        if (mapa.find(par.first) == mapa.end()) {
            all_vertices.pb(par.first);
        }
    }

    return all_vertices;
}

vector<char> subtrair_conjuntos(vector<char> minuendo, set<char> subtraendo) {
    vector<char> novo_array;
    
    for (int i = 0; i < (int) minuendo.size(); i++) {
        char value = minuendo[i];

        if (subtraendo.find(value) == subtraendo.end()) {
            novo_array.pb(value);
        }
    }

    return novo_array;
}

void componentes_fortemente_conexas() {
    vector<char> all_vertices;
    all_vertices = pegar_todos_vertices_grafo();

    while (!all_vertices.empty()) {
        char vertice = all_vertices[0];

        set<char> componentes;

        queue<char> fila;

        fila.push(vertice);

        componentes.insert(vertice);

        while (!fila.empty()) {
            char vertice_atual = fila.front();
            fila.pop();

            for (auto vizinho : grafo[vertice_atual]) {
                if (componentes.find(vizinho) == componentes.end()) {
                    componentes.insert(vizinho);
                    fila.push(vizinho);
                }
            }
        }
        
        fila = queue<char>();
        
        fila.push(vertice);
        
        set<char> componentes_inverso;

        componentes_inverso.insert(vertice);

        while (!fila.empty()) {
            char vertice_atual = fila.front();
            fila.pop();

            for (auto vizin_inv : grafo_inverso[vertice_atual]) {

                if (componentes_inverso.find(vizin_inv) == componentes_inverso.end()) {
                    componentes_inverso.insert(vizin_inv);
                    fila.push(vizin_inv);
                }
                
            }
        }

        set<char> intercecao_componentes;
        
        intercecao_componentes = intersecao_sets(componentes, componentes_inverso);
        all_componentes.pb(intercecao_componentes);

        all_vertices = subtrair_conjuntos(all_vertices, intercecao_componentes);
    }
}

char pegar_primeiro_vertice_grafo() {
    char c = -1;
    for (auto v : grafo) {
        return v.first;
    }
    return c;
}

void imprime_grafo();

void imprime_grafo_inverso();

void imprime_todas_componentes();

int main() {
    fastio;

    char x, y;

    while (cin >> x >> y) {
        grafo[x].insert(y);
        grafo_inverso[y].insert(x);
    }

    componentes_fortemente_conexas();

    imprime_todas_componentes();

    return 0;
}

void imprime_todas_componentes() {
    int cont = 1;
    
    for (int i = 0; i < (int) all_componentes.size(); i++) {
        cout << "Componente " << cont++ << endl;
        for (auto value : all_componentes[i]) {
            cout << value << " ";
        }
        cout << endl;
    }
}

void imprime_grafo() {
    for (auto v : grafo) {
        cout << v.first << " -> ";
        for (auto l : v.second) {
            cout << l << " ";
        }
        cout << endl;
    }
}

void imprime_grafo_inverso() {
    for (auto v : grafo_inverso) {
        cout << v.first << " -> ";
        for (auto l : v.second) {
            cout << l << " ";
        }
        cout << endl;
    }
}

void imprime_set(const set<char> &dados) {
    for (auto v : dados) {
        cout << v << " ";
    }
    cout << endl;
}