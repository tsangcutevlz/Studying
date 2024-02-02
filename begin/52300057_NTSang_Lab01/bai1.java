import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
public class bai1 {


    static public void main(String[] args) {

        int[] arr = { 10, 20, 30, 40, 50, 50, 70, 70 };
        int targetValue = 40;
        int saveIndex = -1;
        int removeElememt = 30;
        int insertValue = 60;
        int insertIndex = 3;
        for(int i = 0;i < arr.length;i++){
            if(arr[i] == targetValue){
                saveIndex = i;
            }
        }
        if(saveIndex == -1){
            System.out.println("There is not exist target value in the array");
        } else {
            System.out.println("Index of " + targetValue + " in array: " + saveIndex);
        }
        int[] newArr = removeElement(arr, removeElememt);
        int[] insertElementArr = insertElement(newArr, insertValue, insertIndex);

        System.out.println("New array after remove " + removeElememt + ":");
        for(int i = 0; i < newArr.length;i++){
            System.out.print(newArr[i] + " ");
        }
        System.out.println("");
        System.out.println("New array after insert " + insertValue + " at index " + insertIndex + ":");
        for(int i = 0; i < insertElementArr.length;i++){
            System.out.print(insertElementArr[i] + " ");
        }

        int max = findMaxElement(arr);
        int min = findMinElement(arr);

        System.out.println("");
        System.out.println("Max value of an array: " + max);
        System.out.println("Min value of an array: " + min);

        int dupArr[] = findDuplicate(arr);
        System.out.println("Duplicate elements in array: ");
        for(int i = 0; i< dupArr.length;i++){
        System.out.print(dupArr[i] + " ");
        }
    }   



    public static int[] removeElement(int[] arr, int element){
        int count = 0;
        int j = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == element){
                count++;
            }
        }
        int[] newArr = new int[arr.length - count];
        for(int i = 0; i < arr.length;i++){
            if(arr[i] != element){
                newArr[j] = arr[i];
                j++;
            } else {
                continue;
            }
        }
        return newArr;
    }

    public static int[] insertElement(int[] arr, int element, int index){
        if (index < 0 || index > arr.length) {
            System.out.println("Invalid index.");
            return arr;
        }

        int[] newArr = new int[arr.length + 1];
        int flag = 0;
        for(int i = 0; i < arr.length;i++){
            flag  = i < index ?  0 :  1;
            newArr[i + flag] = arr[i];
        }
        newArr[index] = element;
        return newArr;
    }

    public static int findMaxElement(int[] arr){
        int max = arr[0];
        for(int i = 0; i < arr.length - 1;i++){
            if(arr[i] < arr[i+1]){
                max = arr[i+1];
            }
        }
        return max;
    }
    public static int findMinElement(int[] arr){
        int min = arr[0];
        for(int i = 0; i < arr.length - 1;i++){
            if(arr[i] > arr[i+1]){
                min = arr[i+1];
            }
        }
        return min;
    }
    public static int[] findDuplicate(int[] arr){
        int[] newArr = new int[arr.length];
        Arrays.sort(arr);
        Set<Integer> dupElement = new HashSet<>();
        int j = 0;
        for(int i = 0; i< arr.length - 1;i++){
            if(arr[i] == arr[i+1]){
                newArr[j] = arr[i];
                j++;
            }
        }
        for(int i = 0; i < newArr.length;i++){
            dupElement.add(newArr[i]);
        }
        int outArr[] = new int[dupElement.size()];
        int index = 0;
        for(int element : dupElement){
            if(element != 0 ){
                outArr[index++] = element;
            }
        }
        int outNewArr[] = new int[outArr.length - 1];
        for(int i = 0; i < outNewArr.length;i++){
            outNewArr[i] = outArr[i];
        }
        return outNewArr;
    }
}
