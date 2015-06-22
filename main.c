#include "gtk-2.0/gtk/gtk.h"

GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

int main( int argc, char *argv[])
{

  GtkWidget *window;
  GtkWidget *table;//tabela contendo os botoes
  GtkWidget *button;
  GtkWidget *display;
  GtkWidget *frame;

  char *values[16] = {
    "7", "8", "9", "/",
    "4", "5", "6", "*",
    "1", "2", "3", "-",
    "0", ".", "=", "+"
  };

  gtk_init(&argc, &argv);//inicia a biblioteca GTK+ (GIMP Tool Kit)

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//cria uma janela do tipo GTK_WINDOW_TOPLEVEL
  gtk_window_set_title(GTK_WINDOW(window), "Calculadora");//define o título
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);//define o tamanho
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//define a posicao inicial
  gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("icon.png"));//define o ícone

  display = gtk_label_new("Display");
  frame = gtk_fixed_new();
  gtk_fixed_put(GTK_FIXED(frame), display, 50, 50);

  //
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  table = gtk_table_new(4, 4, TRUE);//cria uma tabela (janela do tipo GtkTable) com 4 linhas e 4 colunas

  //cria um espaçamento entre as linhas e colunas
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  int i = 0;
  int j = 0;
  int pos = 0;

  //este loop cria os botões e os coloca na tabela
  for( i=0; i < 4; i++) {
    for( j=0; j < 4; j++) {
      button = gtk_button_new_with_label(values[pos]);//nome do botao, que esta no vetor "values"
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1 );
      pos++;//posicao do vetor de caracteres atualizada
    }
  }

  //coloca a tabela na janela "window""
  gtk_container_add(GTK_CONTAINER(window), table);

  //destroi a janela quando clicamos no "x"
  g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  //mostra todos os widgets agregados à janela "window"
  gtk_widget_show_all(window);


  //inicia o loop principal da GTK+
  gtk_main();

  return 0;
}
