#include <iostream>

using namespace std;

int main(){
    struct emprest {
        String dataEmprest, dataDevo, usuemprest;
    };
    
    struct livro {
        int codcatalog, numeropagi;
        string titulolivro, autorelivro, editoralivro;
        char arealivro;
        struct emprest emp;
    };
    
    struct livro livros[100];
    int i, menu, codlivro;
    
    do{
        cout << "Sistema para administrar uma biblioteca." << endl;
        cout << "1 - Cadastrar livro" << endl;
        cout << "2 - Pegar um livro emprestado" << endl;
        cout << "3 - Devolver livros" << endl;
        cout << "4 - Consultar lista de livros" << endl;
        cout << "5-Informar livros disponiveis" << endl;
        cout << "6 - Sair" << endl;
        cout << "Digite a opção desejada:";
        cin >> menu;
        cout << endl << endl;
        
        switch (menu) {
            case 1:
            cout << "Cadastro de livro" << endl;
            cout << endl;
            for (i=0; i<100; i++){
                cout << "Informe os dados cadastrais do" << i+1 << "° livro" << endl;
                cout << "Codigo da Catalogação: ";
                cin >> livros[i].Codigo;
                cout << "Área de conhecimento [(E)xatas, (H)umanos ou (S)aúde]: ";
                cin >> livros[i].arealivro;
                cin.get();
                cout << "Titulo da Obra: ";
                getline (cin, livros[i].titulolivro);
                cout << "Autores da obra: ";
                getline (cin, livros[i].autorelivro);
                cout << "Editora:  ":
                getline (cin, livros[i].editoralivro);
                cout << "Número de páginas: ";
                cin >> livros[i].numeropagi;
            }
            break;
            case 2:
            cout << "Emprestimo de Livros" << endl;
            cout << "informe o código do livro: ";
            cin >> codlivro;
            for (i=0; i<100; i++){
                if (livros[i].codcatalog == codlivro){
                    cout << "Data de emprestimo: ";
                    cin.get();
                    getline (cin, livros[i].emp.dataEmprest);
                    cout << "Data de devolução: ";
                    getline (cin, livros[i].emp.dataDevo);
                    cout << "Usuário: ";
                    getline (cin, livros[i].emp.usuemprest);
                    
               
            }
        }
        break;
        case 3:
        cout << "Devolução de livros" << endl;
        cout << "Informe o código do livro: ";
        cin >> codlivro;
        for (i=0; i<100; i++){
            if (livros[i].codcatalog == codlivro){
                livros[i].emp.dataEmprest = "";
                livros[i].emp.dataDevo = "";
                livros[i].emp.usuemprest = "";
            }
        }
        break;
        case 4:
        cout << "Consulta de livros" << endl;
        cout << "Informe o código do livro: ";
        cin >> codlivro;
        for (i=0; i<100; i++){
            if (livros[i].codcatalog == codlivro){
                cout << "Código de catalogação: " << livros[i].codcatalog << endl;
                cout << "Área de conhecimento: " << livros[i].arealivro << endl;
                cout << "Título da obra: " << livros[i].titulolivro << endl;
                cout << "Autores da obra: " << livros[i].autorelivro << endl;
                cout << "Editora: " << livros[i].editoralivro << endl;
                cout << "Número de páginas: " << livros[i].numeropagi << endl;
            if (livros[i].emp.dataEmprest != ""){
                cout << "Data de empréstimo: " <<livros[i].emp.dataEmprest << endl;
                cout << "Data de devolução: " << livros[i].emp.dataDevo << endl;
                cout << "Usuário: " << livros[i].emp.usuemprest << endl;
            }
            cin.ignore();
            cin.get();
            }
        }
        break;
    case 5:
        cout << "Livros Disponiveis" << endl;
        for (i=0; i <100; i++){
            if (livros[i].emp.usuemprest == ""){
                cout << "Código de catalogação: " << livros[i].codcatalog << endl;
                cout << "Área de conhecimento: " << livros[i].arealivro << endl;
                cout << "Título da obra: " << livros[i].titulolivro << endl;
                cout << "Autores da obra: " << livros[i].autorelivro << endl;
                cout << "Editora: " << livros[i].editoralivro << endl;
                cout << "Número de páginas: " << livros[i].numeropagi << endl;
                cout << "------------------------------------------------------------------" << endl;
            }
        }
            
        cin.ignore();
        cin.get();
        break;
        } 
cout << "\e[2J" << "\e[0;0H";
system("cls");
    } while (menu !=6);
}
