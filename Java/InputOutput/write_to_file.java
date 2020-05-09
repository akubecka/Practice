//package Java.InputOutput; You do not need a package if you only have one file
/*
 * This code reads from the file and prints it back on command line
 * Running instructions: 
 * 1. javac *.java (compiles all files with .java ending)
 * 2. java ./<filename>
 * 
 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class write_to_file {
    public static void main(String[] args) {
        try {
          File myObj = new File("filename.txt");
          if (myObj.createNewFile()) {
            System.out.println("File created: " + myObj.getName());
          } else {
            System.out.println("File already exists.");
          }
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
        }
        try {
            FileWriter myWriter = new FileWriter("filename.txt");
            myWriter.write("Files in Java might be tricky, but it is fun enough!");
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
          } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
          }
      }

}