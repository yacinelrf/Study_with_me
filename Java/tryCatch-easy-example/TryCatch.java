public class TryCatch {
    public static void Catcher(int[] tab,int i ){
        if(i<0 || i>tab.length){
            throw new ArrayIndexOutOfBoundsException("try with a small nember next timeeeee :)");

        }
        else{
            for(int j=0;j<i;j++){
                System.out.println(tab[j]);
             }

        }


    }
   public static void main(String args[]){
    //array contains can only be used to initialisers
     int[] tab={1,2,3,5,4};
     try{
        Catcher(tab, 5);
     }catch(ArrayIndexOutOfBoundsException e){
        System.out.println(e);

     }

    

   }
}
