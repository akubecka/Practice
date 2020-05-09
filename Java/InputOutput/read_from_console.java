//package Java.InputOutput; You do not need a package if you only have one file
/*
 * This code reads from the command line and prints it back on command line
 * Running instructions: 
 * 1. javac *.java (compiles all files with .java ending)
 * 2. java ./<filename>
 * 
 */
public class read_from_console{
    public static void main(String[] args){
        String input = System.console().readLine();
        System.out.println(input);
    }
}