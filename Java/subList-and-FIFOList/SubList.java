import java.lang.reflect.Array;
import java.util.*;

public class SubList<E> implements List<E>{
    public List <E> supportliste;
    public int fromIndex;
    public int toIndex;

    public SubList(List<E> supportList,int fromIndex,int toIndex){
        if(supportList==null){
            throw new NullPointerException("la supportlist ne peut pas etre null ");
        }
        if(fromIndex<0 || toIndex>supportList.size() || fromIndex>toIndex){
            throw new IndexOutOfBoundsException("les indexes entrees sont invalides");
        }

        this.supportliste=supportList;
        this.fromIndex=fromIndex;
        this.toIndex=toIndex;
    }

    public List<E> getSupportList(){
        return supportliste;
    }

    public int startInSupportList(){
        return fromIndex;
    }

    public int toIndexInSupportList(){
        return toIndex;
    }



    @Override
    public int size(){
        return toIndex-fromIndex;
    }

    @Override
    public boolean add(E o){ 

         supportliste.add(toIndex,o);
         toIndex++;
         return true;
    }

    @Override
    public void add(int index, E element){
        if(index<fromIndex || index>toIndex){
            throw new IndexOutOfBoundsException("les indices que vous avez entrer sont invalides");
        }
        supportliste.add(index+fromIndex, element);
        toIndex++;
    }

    @Override
    public boolean addAll(int index, Collection<? extends E> c){
        if(index<fromIndex || index>toIndex){
            throw new IndexOutOfBoundsException("les indices que vous avez entrer sont invalides");
        }
        if(c==null){
            throw new NullPointerException("la liste que vous voulez ajouter a cette subliste est null");
        }
        toIndex+=c.size();
        return supportliste.addAll(fromIndex+index,c);
    }

    @Override
    public boolean containsAll(Collection<?> c){
        if(c==null){
            throw new NullPointerException("la liste que vous voulez ajouter a cette subliste est null");
        }
        return supportliste.subList(fromIndex, toIndex).containsAll(c);
    }

    @Override
    public boolean remove(Object o){
        int index=supportliste.subList(fromIndex, toIndex).indexOf(o);
        if(index ==-1){
            return false;
        }
        supportliste.remove(index+fromIndex);
        return true;
    }

    public boolean equals(Collection<?> c){

        if(!(c.size()==supportliste.size()&& c instanceof List)){
            return false;
        }
        List<E> l=(List<E>) c;
        return l.equals(supportliste);
    }

    public int hashCode(){
        return fromIndex+toIndex+31*supportliste.hashCode()+31*supportliste.hashCode();
    }

    // Méthodes redirigeant les appels vers la sous-liste
    @Override
    public E get(int index) {
        if (index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Index hors limites.");
        }
        return supportliste.get(fromIndex + index);
    }

    @Override
    public E set(int index, E element) {
        if (index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Index hors limites.");
        }
        return supportliste.set(fromIndex + index, element);
    }

    @Override
    public E remove(int index) {
        if (index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Index hors limites.");
        }
        return supportliste.remove(fromIndex + index);
    }

    @Override
    public Iterator<E> iterator() {
        return supportliste.subList(fromIndex,toIndex).iterator();
    }

    @Override
    public ListIterator<E> listIterator() {
        return supportliste.subList(fromIndex,toIndex).listIterator();
    }

    @Override
    public ListIterator<E> listIterator(int index) {
        return supportliste.subList(fromIndex,toIndex).listIterator(index);
    }

    @Override
    public List<E> subList(int fromIndex, int toIndex) {
        if (fromIndex < 0 || toIndex > size() || fromIndex > toIndex) {
            throw new IndexOutOfBoundsException("Indices invalides pour la sous-liste.");
        }
        return new SubList<>(supportliste, fromIndex + fromIndex,fromIndex + toIndex);
    }

    @Override
    public boolean isEmpty() {
        return size() == 0;
    }

    @Override
    public boolean contains(Object o) {
        return supportliste.subList(fromIndex,toIndex).contains(o);
    }

    @Override
    public int indexOf(Object o) {
        int index = supportliste.subList(fromIndex,toIndex).indexOf(o);
        return index >= 0 ? index : -1;
    }

    @Override
    public int lastIndexOf(Object o) {
        int index = supportliste.subList(fromIndex,toIndex).lastIndexOf(o);
        return index >= 0 ? index : -1;
    }

    @Override
    public void clear() {
        supportliste.subList(fromIndex,toIndex).clear();
    }

    @Override
    public Object[] toArray() {
        return supportliste.subList(fromIndex,toIndex).toArray();
    }

    @Override
    public <T> T[] toArray(T[] a) {
        return supportliste.subList(fromIndex,toIndex).toArray(a);
    }

    @Override
    public boolean removeAll(Collection<?> c) {
        return supportliste.subList(fromIndex,toIndex).removeAll(c);
    }

    @Override
    public boolean retainAll(Collection<?> c) {
        return supportliste.subList(fromIndex,toIndex).retainAll(c);
    }
    @Override
    public boolean addAll(Collection <? extends E> c){
        if(c ==null){
            throw new NullPointerException("la liste que vous avez entre est null");
        }
        toIndex+=c.size();
        supportliste.subList(fromIndex, toIndex).addAll(c);
        return true;

    }













}