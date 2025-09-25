import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        int port = 8088; 
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is listening on port " + port);
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("New client connected: " + socket.getInetAddress().getHostAddress());
                new ClientHandler(socket).start();
            }
        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}
class ClientHandler extends Thread {
    private Socket socket;
    public ClientHandler(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try (InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true)) {
            String text;
            while ((text = reader.readLine()) != null) {
                System.out.println("Received from client: " + text);
                writer.println("Server: " + text);
            }
        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        } finally {
            try {
                socket.close();
                System.out.println("Client disconnected: " + socket.getInetAddress().getHostAddress());
            } catch (IOException ex) {
                System.out.println("Error closing socket: " + ex.getMessage());
            }
        }
    }
}