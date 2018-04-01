/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtusetmap;
import java.security.InvalidParameterException;
import java.util.*;
/**
 *
 * @author rabia
 * @param <T> for template element for implement
 */
@SuppressWarnings("unchecked")
public class GTUSet<T> implements GTUSetInt<T>{
    
    protected int capacity;
    protected int used;
    Object array[];
    
    public GTUSet(){
        capacity=50;
        used=0;
        array = (T[])new Object [capacity];
        for (int i = 0; i < capacity; i++) {
            array[i] = 0;
        }
    }
    public GTUSet(int in_capacity){
        capacity=in_capacity;
        used=0;
        array = (T[])new Object [capacity];
        
    }
    /**
     * @return true, if set array empty
     */
    @Override
    public boolean empty(){
        if(used==0){
            return true;
        }
        return false;
    }

    /**
     * @return used(size) value for set array
     */
    @Override
    public int size(){
        return used;
    }

    /**
     * @return capacity for set array
     */
    @Override
    public int max_size(){
        return capacity;
    }

    /**
     * @param element insert the set array, if set array is not contain
     * @throws InvalidParameterException if existing element throw this exception
     */
    @Override
    public void insert(Object element) throws InvalidParameterException{
        if(used>=capacity){
            Object array_b[];
            array_b = (T[])new Object[used];
            for(int i=0; i<used; i++){
                array_b[i]=array[i];
            }
            array = (T[])new Object [capacity*2];
            for(int i=0; i<used; i++){
                array[i]=array_b[i];
            }
            capacity*=2;
        }
        if(!itContains((T) element)){
            array[used] = element;
            used++;
            Arrays.sort(array,0,used);
        }
        else if(itContains((T) element)){
            throw new InvalidParameterException("COULD NOT EXISTING ELEMENT INSERT !!");
            }
        }

    /**
     * @param value searching value in the set array
     * @return if find returns true, else returns false
     */
    @Override
    public boolean itContains(T value){
        boolean isContains=false;
        for(int i=0; i<capacity; i++){
            if(array[i]==value){
                isContains=true;
                break;
            }
        }
        return isContains;
    }

    /**
     *
     * @param element if find element in set array, erase it
     * @throws InvalidParameterException could not throw it
     */
    @Override
    public void erase(Object element)throws InvalidParameterException{
        if(!itContains((T) element)){
            throw new InvalidParameterException("COULD NOT EXISTING ELEMENT ERASE !!");
        }
        else if(itContains((T) element)){
            int i, j;
            for(i=0; i<used; i++){
                if(array[i]==element){
                        break;
                }
            }
            for(j=i; j<used-1; j++){
                array[j]=array[j+1];
            }
            used--;
        }
    }

    /**
     * use for total elements clean
     */
    @Override
    public void clear(){
        used=0;
    }

    /**
     * @param value searching element
     * @return finding element count
     */
    @Override
    public int count(Object value){
        int count=0;
        for(int i=0; i<capacity; i++){
            if(array[i]==value){
                count++;
            }
        }
        return count;
    }
    /**
     * @param value search value in set array
     * @return GTUIterator pointer for find value
     */
    @Override
    public GTUIterator<T> find(T value){
        GTUIterator<T> ptr= new GTUIterator();
        for(int i=0; i<used; i++){
            if(array[i]==value){
                break;
            }
            if(ptr.hasNext()){
                ptr.next();
            }
        }
        return ptr;
    }

    /**
     * @return GTUIterator pointer, set array first element
     */
    @Override
    public GTUIterator<T> begin(){
        GTUIterator<T> ptr= new GTUIterator();
        return ptr;
    }
    
    /**
     * @return GTUIterator pointer, set array last element
     */
    @Override
    public GTUIterator<T> end(){
        GTUIterator<T> ptr= new GTUIterator();
        for(int i=0; i<used-1; i++){
            if(ptr.hasNext()){
                ptr.next();
            }
            
        }
        return ptr;
    }
    /**
     * 
     * @param other for contrast GTUSet object
     * @return intersection set object
     */
    @Override
    public GTUSet<T> setIntersection(GTUSet<T> other){
        GTUSet newset = new GTUSet(used);
        System.out.print("Intersection for first and second set: ");
        for(int i=0; i<used; i++){
            for(int j=0; j<other.used; j++){
                if(array[i]==other.array[j]){
                    newset.insert(array[i]);
                    System.out.print(array[i] +" ");
                    break;
                }
            }
        }
	System.out.println();
	return newset;
    }
    @Override
    public void printContent(){
        
        for(int i=0; i<used; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
    public class GTUIterator<T>{
        //Array icerisinde dolasmak icin temporary bir index olusturuldu.
        private int iterIndex = 0;
        public GTUIterator(){
            
        }
        public boolean hasNext(){
            if(iterIndex<capacity && array[iterIndex]!=null){
                return true;
            }
            return false;
        }
        public boolean hasPrevious(){
            if(iterIndex>0 && iterIndex<capacity && array[iterIndex]!=null){
                return true;
            }
            return false;
        }
        public T next(){
            return (T) array[++iterIndex];
        }
        public T previous(){
            if(iterIndex>0){
                return (T) array[--iterIndex];
            }
            return null;  
        }
    }
}
