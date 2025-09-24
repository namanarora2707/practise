import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String hostname = "localhost";
        int port = 8088;

        try (Socket socket = new Socket(hostname, port)) {
            System.out.println("Connected to server at " + hostname + ":" + port);
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
            String userInput;
            System.out.println("Enter messages to send to the server (type 'exit' to quit):");
            while (true) {
                userInput = consoleReader.readLine();
                if (userInput == null || userInput.equalsIgnoreCase("exit")) {
                    break; 
                }
                writer.println(userInput);
                String response = reader.readLine();
                System.out.println(response);
            }
        } catch (UnknownHostException ex) {
            System.out.println("Server not found: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("I/O error: " + ex.getMessage());
        } finally {
            System.out.println("Client disconnected.");
        }
    }
}

