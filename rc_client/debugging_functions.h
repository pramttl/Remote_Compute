#ifndef DEBUGGING_FUNCTIONS_H
#define DEBUGGING_FUNCTIONS_H

/*
  These functions are useful for Debugging with Byte Arrays and other types of Qt Objects and to print them appropriately to a debug file.
*/

#include <QByteArray>
#include <QString>

/// DEBUGGING FUNCTION FOR A PDU ITEM
void Debug_Byte_Array(char * title, QByteArray PDU_Item){

    int PDU_length = PDU_Item.size();
    FILE * fp;
    int i = 0;
    fp = fopen("debug_file.txt","a+");

    fprintf(fp,"%s \n", title);
    fprintf(fp,"ITEM Size: %d \n", PDU_length);

    QString PDUString = static_cast<QString>(PDU_Item.toHex());

    QString byte_str;;

    for (i=0; i < PDUString.size() - 1; i++){
        byte_str = PDUString.mid(i++,2);
        fprintf(fp,"%s ", qPrintable(byte_str));
    }
    fprintf(fp,"\n\n");
    fclose(fp);
}

/// DEBUGGING FUNCTION FOR A PDU ITEM
void Debug_Initialisation(char * title){
    FILE * fp;
    fp = fopen("debug_file.txt","w+");
    fprintf(fp,"PDU Title: %s \n", title);
    fclose(fp);
}


/// DEBUGGING FUNCTION FOR STRING
void Debug_DICOM_String(char *title, QString debug_str){
    FILE * fp;
    fp = fopen("debug_file.txt","a+");
    fprintf(fp,"%s:    ", title);
    fprintf(fp,"%s\n", qPrintable(debug_str));
    fclose(fp);
}


/// DEBUGGING FUNCTION FOR STRING
void Debug_DICOM_Integer(char *title, int debug_val){
    FILE * fp;
    fp = fopen("debug_file.txt","a+");
    fprintf(fp,"%s:    ", title);
    fprintf(fp,"%d \n", debug_val);
    fclose(fp);
}

#endif // DEBUGGING_FUNCTIONS_H
