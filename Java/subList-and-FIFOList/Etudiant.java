public class Etudiant{
    public String nom;
    public String prenom;
    public int numeroEtudiant;

    public Etudiant(String nom,String prenom,int numeroEtudiant){
        this.nom=nom;
        this.prenom=prenom;
        this.numeroEtudiant=numeroEtudiant;
    }
    public void Afficher(){
        System.out.println("Nom: "+nom+"Prenom: "+prenom+"numero d'etudiant: "+numeroEtudiant);
    }
}