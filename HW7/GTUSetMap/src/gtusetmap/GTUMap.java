/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gtusetmap;

import java.security.InvalidParameterException;
import javafx.util.Pair;

/**
 *
 * @author rabia
 * @param <K> for template value Key
 * @param <V> for template value Value
 * 
 */
public class GTUMap<K,V> extends GTUSet<javafx.util.Pair <K, V> > {
    
    public GTUMap(){
        super();
    }
    public GTUMap(int in_capacity){
        super(in_capacity); 
    }
    /**
     *
     * @param p for inserting element Object, casting to pair
     * @throws InvalidParameterException throws existing key value
     */
    @Override
    public void insert(Object p) throws InvalidParameterException{
        if(used>=capacity){
            Object array_b[];
            array_b = (Pair[])new Object[used];
            for(int i=0; i<used; i++){
                array_b[i]=array[i];
            }
            array = (Pair[])new Object [capacity*2];
            for(int i=0; i<used; i++){
                array[i]=array_b[i];
            }
            capacity*=2;
        }
        if(count(p)!=1){
            array[used]=new Pair(((Pair)p).getKey(), ((Pair)p).getValue());
            used++;
        }
        else{
            throw new InvalidParameterException("COULD NOT EXISTING KEY ELEMENT INSERT!!");
        }
    }

    /**
     *
     * @param value search in array
     * @return count if contains return 1, else returns 0
     */
    @Override
    public int count(Object value){
        int count=0;
        for(int i=0; i<capacity; i++){
            if(array[i].equals(value)==true){
                count++;
            }
        }
        return count;
    }
    /**
     * 
     * @param p for erase element, if array contains
     * @throws InvalidParameterException array is not contain p, throws exception
     */
    @Override
    public void erase(Object p)throws InvalidParameterException{
        if(count(p)==0){
            throw new InvalidParameterException("COULD NOT EXISTING ELEMENT ERASE !!");
        }
        else if(count(p)==1){
            int i, j;
            for(i=0; i<used; i++){
                if(array[i].equals(p)==true){
                        break;
                }
            }
            for(j=i; j<used-1; j++){
                (array[j])=new Pair(((Pair)array[j+1]).getKey(),((Pair)array[j+1]).getValue());
            }
            used--;
        }
    }
    /**
     * 
     * @param k searching key in map array
     * @return V parameter found key value in mapped array
     */
    public V at(K k){
        for(int i=0; i<capacity; i++){
            if(((Pair)array[i]).getKey()== k){
                System.out.println((V) ((Pair)array[i]).getValue());
                return (V) ((Pair)array[i]).getValue();
            }
        }
        return null;
    }
    /**
     * @param search value in map array
     * @return GTUIterator pointer for find value
     *
     */
    @Override
    public GTUIterator<Pair<K,V> > find(Pair<K,V> search){
        GTUIterator<Pair<K,V>> ptr= new GTUIterator();
        int i;
        for(i=0; i<used; i++){
            if(array[i].equals(search)){
                break;
            }
            ptr.next();
        }
        return  ptr;
    }
    /**
     * 
     * @param other for contrast GTUMap object
     * @return intersection map object
     *
     */
    public GTUMap<K,V> setIntersection(GTUMap<K,V> other){
        GTUMap newMap = new GTUMap(used);
        System.out.print("Intersection for first and second map: ");
        for(int i=0; i<used; i++){
            for(int j=0; j<other.used; j++){
                if(((Pair)array[i]).getKey()==((Pair)other.array[j]).getKey()){
                    newMap.array[i]= new Pair(((Pair)array[i]).getKey(),((Pair)array[i]).getValue());
                    System.out.print(((Pair)array[i]).getKey()+"=");
                    System.out.print(((Pair)array[i]).getValue()+" ");
                }
            }
        }
	System.out.println();
	return newMap;
    }
}
