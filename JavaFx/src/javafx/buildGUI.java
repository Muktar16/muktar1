
package javafx;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class buildGUI extends Application {
    
    public static void main(String[] args) {
        
        launch(args);      
    }

    @Override
    public void start(Stage stage) throws Exception {
        
        StackPane pane = new StackPane();
        Button btn = new Button();
        btn.setText("Click me");
        
        pane.getChildren().add(btn);
        pane.setMinHeight(300);
        pane.setMinWidth(500);
        
        Scene scene = new Scene(pane);
        
        stage.setScene(scene);
        stage.show();
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
