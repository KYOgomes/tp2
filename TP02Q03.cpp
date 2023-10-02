import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ListaPersonagens {

    private static final int TAMANHO_INICIAL = 10;
    private Personagem[] elementos;
    private int tamanho;

    public ListaPersonagens() {
        this.elementos = new Personagem[TAMANHO_INICIAL];
        this.tamanho = 0;
    }

    public void inserirInicio(Personagem personagem) {
        if (this.tamanho == this.elementos.length) {
            this.aumentarCapacidade();
        }
        for (int i = this.tamanho; i > 0; i--) {
            this.elementos[i] = this.elementos[i-1];
        }
        this.elementos[0] = personagem;
        this.tamanho++;
    }

    public void inserir(Personagem personagem, int posicao) {
        if (posicao < 0 || posicao > this.tamanho) {
            throw new IndexOutOfBoundsException("Posição inválida!");
        }
        if (this.tamanho == this.elementos.length) {
            this.aumentarCapacidade();
        }
        for (int i = this.tamanho; i > posicao; i--) {
            this.elementos[i] = this.elementos[i-1];
        }
        this.elementos[posicao] = personagem;
        this.tamanho++;
    }

    public void inserirFim(Personagem personagem) {
        if (this.tamanho == this.elementos.length) {
            this.aumentarCapacidade();
        }
        this.elementos[this.tamanho] = personagem;
        this.tamanho++;
    }

    public Personagem removerInicio() {
        if (this.tamanho == 0) {
            throw new IndexOutOfBoundsException("Lista vazia!");
        }
        Personagem removido = this.elementos[0];
        for (int i = 0; i < this.tamanho - 1; i++) {
            this.elementos[i] = this.elementos[i+1];
        }
        this.elementos[this.tamanho - 1] = null;
        this.tamanho--;
        return removido;
    }

    public Personagem remover(int posicao) {
        if (posicao < 0 || posicao >= this.tamanho) {
            throw new IndexOutOfBoundsException("Posição inválida!");
        }
        Personagem removido = this.elementos[posicao];
        for (int i = posicao; i < this.tamanho - 1; i++) {
            this.elementos[i] = this.elementos[i+1];
        }
        this.elementos[this.tamanho - 1] = null;
        this.tamanho--;
        return removido;
    }

    public Personagem removerFim() {
        if (this.tamanho == 0) {
            throw new IndexOutOfBoundsException("Lista vazia!");
        }
        Personagem removido = this.elementos[this.tamanho - 1];
        this.elementos[this.tamanho - 1] = null;
        this.tamanho--;
        return removido;
    }

    private void aumentarCapacidade() {
        Personagem[] novoArray = new Personagem[this.elementos.length * 2];
        for (int i = 0; i < this.elementos.length; i++) {
            novoArray[i] = this.elementos[i];
        }
        this.elementos = novoArray;
    }

    public static void main(String[]
