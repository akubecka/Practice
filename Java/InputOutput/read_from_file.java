//package Java.InputOutput; You do not need a package if you only have one file
/*
 * This code reads from the file and prints it back on command line
 * Running instructions: 
 * 1. javac *.java (compiles all files with .java ending)
 * 2. java ./<filename>
 * 
 */
import java.io.*;
public class read_from_file {
    public static void main(String[] args)throws Exception{ 

    // We need to provide file path as the parameter: 
    // double backquote is to avoid compiler interpret words 
    // like \test as \t (ie. as a escape sequence) 
    File file = new File("test.txt"); 
    
    BufferedReader br = new BufferedReader(new FileReader(file)); 
    String st; 
    while ((st = br.readLine()) != null) 
        System.out.println(st); 
    } 
}