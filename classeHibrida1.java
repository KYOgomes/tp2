
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

class classeHibrida1{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Personagens psg = new Personagens();
        String line;

        line = sc.nextLine();

            while(Fim(line) == false){

                psg.Ler(line);
                psg.Imprimir();
                line = sc.nextLine();
                
            }
        sc.close();
    }

    private static boolean Fim(String str) {
        boolean resp = false;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            resp = true;
        }

        return resp;
    }
}

class Personagens{

    private int altura;
    private double peso;
    private String nome, corDoCabelo, corDaPele, corDosOlhos, anoNascimento, genero, homeworld;

    public Personagens(){
        this.nome = this.corDoCabelo = this.corDaPele = this.corDosOlhos = this.anoNascimento = this.genero = this.homeworld = null;
        this.altura = 0;
        this.peso = 0;
    }

    public Personagens(String nome, int altura, double peso, String corDoCabelo, String corDaPele, String corDosOlhos, String anoDeNascimento, String genero, String homeworld){
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
        this.corDoCabelo = corDoCabelo;
        this.corDaPele = corDaPele;
        this.corDosOlhos = corDosOlhos;
        this.anoNascimento = anoDeNascimento;
        this.genero = genero;
        this.homeworld = homeworld;
    }

    public void setNome(String nome) {this.nome = nome;}
    public void setAltura(int altura) {this.altura = altura;}
    public void setPeso(double peso) {this.peso = peso;}
    public void setCorDoCabelo(String corDoCabelo) {this.corDoCabelo = corDoCabelo;}
    public void setCorDaPele(String corDaPele) {this.corDaPele = corDaPele;}
    public void setCorDosOlhos(String corDosOlhos) {this.corDosOlhos = corDosOlhos;}
    public void setAnoNascimento(String anoNascimento) {this.anoNascimento = anoNascimento;}
    public void setGenero(String genero) {this.genero = genero;}
    public void setHomeworld(String homeworld) { this.homeworld = homeworld;}

    public String getNome() {return nome;}
    public int getAltura() {return altura;}
    public double getPeso() {return peso;}
    public String getCorDoCabelo() {return corDoCabelo;}
    public String getCorDaPele() {return corDaPele;}
    public String getCorDosOlhos() {return corDosOlhos;}
    public String getAnoNascimento() {return anoNascimento;}
    public String getGenero() {return genero;}
    public String getHomeworld() {return homeworld;}

    public Personagens Clone(){

        Personagens clonado = new Personagens();

        clonado.nome = this.nome;
        clonado.altura = this.altura;
        clonado.peso = this.peso;
        clonado.corDoCabelo = this.corDoCabelo;
        clonado.corDaPele = this.corDaPele;
        clonado.corDosOlhos = this.corDosOlhos;
        clonado.anoNascimento = this.anoNascimento;
        clonado.genero = this.genero;
        clonado.homeworld = this.homeworld;
        return clonado;
    }


    public void Imprimir(){
        System.out.print(" ## " + nome + " ## " + altura + " ## ");

        if((peso % 1) == 0)
            System.out.print((int)peso);
        else
            System.out.printf(Locale.ENGLISH, "%.1f", peso);

        System.out.println(" ## " + corDoCabelo + " ## " + corDaPele + " ## " + corDosOlhos + " ## " + anoNascimento + " ## " + genero + " ## " + homeworld + " ## " );
    }

    public void Ler(String ender){

        try {
            FileReader fr = new FileReader(ender);
            BufferedReader br = new BufferedReader(fr);
            String texto, tAlt, tPeso;
            String[] linhas;

            texto = br.readLine();


            linhas = texto.split("',");
            
         
            this.nome = linhas[0].substring(10,linhas[0].length());
            tAlt = linhas[1].substring(12,linhas[1].length());
            tPeso = linhas[2].substring(10,linhas[2].length());
            this.corDoCabelo = linhas[3].substring(16,linhas[3].length());
            this.corDaPele = linhas[4].substring(16,linhas[4].length());
            this.corDosOlhos = linhas[5].substring(15,linhas[5].length());
            this.anoNascimento = linhas[6].substring(16,linhas[6].length());
            this.genero = linhas[7].substring(12,linhas[7].length());
            this.homeworld = linhas[8].substring(15,linhas[8].length());
        
            if(tPeso.contains(",")){
                tPeso = tPeso.replace(",", "");
            }
            
            if(tAlt.equals("unknown"))
                this.altura = 0;
            else
                this.altura = Integer.parseInt(tAlt);

            if(tPeso.equals("unknown"))
                this.peso = 0;
            else
                this.peso = Double.parseDouble(tPeso);
            
            br.close();
        } 
        catch (FileNotFoundException fnf){
            fnf.printStackTrace();
        }

        catch (IOException e) {
            e.printStackTrace();
        }
    }

}