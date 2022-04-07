#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
 
/*创建一个纵向盒，它包含一个图像和一个标签*/
GtkWidget *image_label_box(gchar *filename,gchar *label_text)
{
    GtkWidget *vbox;
    GtkWidget *label;
    GtkWidget *image;
 
    /*为图像和标签创建横向盒*/
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_set_border_width(GTK_CONTAINER(vbox),1);
 
    /*为按钮创建一个图像*/
    image = gtk_image_new_from_file(filename);
 
    /*为按钮创建一个标签*/
    label = gtk_label_new(label_text);
 
    /*图像和标签组装到盒子里*/
    gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,0);
 
    return vbox;
}
 
 
/*回调函数
 *传到这个函数的数据打印到标准输出
 * */
void callback(GtkWidget *widget, gpointer data)
{
    g_print("Hello again -%s was pressed\n",(char *) data);
}
 
/*退出回调函数*/
gint delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
    gtk_main_quit();
    return FALSE;
}
 
int main(int argc,char *argv[])
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
 
    /*初始化*/
    gtk_init(&argc,&argv);
 
    /*创建窗口*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 
    /*这个一般必要有delete_event信号到主窗口*/
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(delete_event),NULL);
    
    /*设置窗口宽度*/
    gtk_container_set_border_width(GTK_CONTAINER(window),400);
 
    /*设置窗口标题*/
    gtk_window_set_title(GTK_WINDOW(window),"按钮示例");
 
    button = gtk_button_new();
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(callback),(gpointer)"记事本");
 
    box = image_label_box("/home/zt/icons/gedit.png","记事本");//传回一个纵向组装盒
    gtk_container_add(GTK_CONTAINER(button),box);
    gtk_container_add(GTK_CONTAINER(window),button);
 
    gtk_widget_show_all(window);
 
    gtk_main();
    return 0;
}
