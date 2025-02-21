import java.util.ArrayList;
import java.util.*;
public class ArrayFIFOList<E> extends ArrayList<E>{
    public ArrayFIFOList(){
        super();
    }


    public E remove(){
        if (isEmpty()) {
            throw new NoSuchElementException("La liste est vide.");
        }
        return super.remove(0);
    }

    public E get(){
        if (isEmpty()) {
            throw new NoSuchElementException("La liste est vide.");
        }
        return super.get(0);
    }

    public int rank(Object o){
        if(!this.contains(o)){
            return -1;
        }
        return this.indexOf(o)+1;

    }
    
}
