import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Arrays;
public class bai4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String tempString = sc.nextLine();
        String[][] output = processParagraph(tempString);
        printString(output, tempString);
    }
    public static String[][] processParagraph(String paragraph){
        String[] words = paragraph.split("\\s+");
        for(int i = 0; i < words.length;i++){
            words[i] = words[i].replaceAll("[^a-zA-Z]", "");
        }
        Arrays.sort(words);
        int count = 1;
        int countLength = 1;
        String[][] result = new String[words.length][2];
        int j = 0;
        for(int i = 0; i < words.length-1; i++){
            if(words[i].equals(words[i + 1])){
                count++;
            } else {
                result[j][0] = String.valueOf(count);
                result[j][1] = words[i];
                countLength++;
                count = 1;
                j++;
            }
            if((i == words.length - 2) && !(words[words.length-1].equals(words[words.length-2]))){
                result[j][0] = String.valueOf(count);
                result[j][1] = words[words.length - 1];
            } 
            if((i == words.length - 2) && (words[words.length-1].equals(words[words.length-2]))){
                result[j][0] = String.valueOf(count);
                result[j][1] = words[words.length - 1];
            } 
        }
        String[][] output = new String[countLength][2];
        for(int i = 0; i < countLength;i++){
            output[i][0] = result[i][0];
            output[i][1] = result[i][1];
        }
        return output;
    }


    public static void printString(String[][] result, String tempString){
        String delimiters = "[ ,.!?]+";
        StringTokenizer splitString = new StringTokenizer(tempString, delimiters);
        StringBuffer buffer = new StringBuffer();
        while(splitString.hasMoreTokens()){
            String token = splitString.nextToken();
            if(buffer.indexOf(token) == -1){
                buffer.append(token);
                for (int i = 0; i < result.length; i++) {
                    if (token.equals(result[i][1])) {
                        System.out.println(result[i][0] + " " + result[i][1]);
                        break;
                    }
                }
            }
        }
    }
}
