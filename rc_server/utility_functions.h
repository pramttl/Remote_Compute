#ifndef CONVERSION_GENERATION_FUNCTIONS_H
#define CONVERSION_GENERATION_FUNCTIONS_H

/*
  This file contain's general utility functions for C++ & QT conversions and generation of common objects,
  that have nothing to do in particular with DICOM.
  However, these functions are very important & useful in the SenoClient Application.
*/

#include <QByteArray>

QByteArray Invert_Byte_Order(QByteArray input_byte_array){
    int i = 0;
    QByteArray temp_byte_array;
    for ((i=input_byte_array.size() - 1);i>=0;i--){
        temp_byte_array.append(input_byte_array.at(i));
    }
    return temp_byte_array;
}

QByteArray int_to_qb_array_LE(int num, int length_in_bytes)
{
    QByteArray num_in_bytes((const char *)&num, length_in_bytes);

    return num_in_bytes;
}

QByteArray int_to_qb_array_BE(int num, int length_in_bytes)
{
    QByteArray num_in_bytes((const char *)&num, length_in_bytes);
    num_in_bytes = Invert_Byte_Order(num_in_bytes);

    return num_in_bytes;
}


QByteArray N_Zero_Bytes(int number_of_bytes)
{
    QByteArray return_bytes;

    int i = 0;
    for (i=0; i < number_of_bytes; i++){
        return_bytes.append(QByteArray::fromHex("00"));
    }

    return return_bytes;
}

char * QString_to_CString(QString q_str) {
    QByteArray ba = q_str.toLocal8Bit();
    char *c_str = ba.data();
    return c_str;
}


// Eg. bc000000 will be converted to 188.
// Only Give little Endian Input to this.
int Hex_Bytes_to_Integer(QByteArray little_endian_bytes){
    int num = 0;
    memcpy(&num, little_endian_bytes, little_endian_bytes.size());
    return num;
}


// Similar to prev function, but takes Big Endian Bytes.
int Hex_Bytes_BE_to_Integer(QByteArray bytes){
    int num = 0;
    bytes = Invert_Byte_Order(bytes);
    // bytes is now in Little Endian form.
    memcpy(&num, bytes, bytes.size());
    return num;
}

// Returns a QByteArray with just a single Byte corresponding to the input unsigned hex character.
QByteArray uns_char_to_qb_array(unsigned char ch){
    static const char mydata[] = {ch};
    QByteArray byte = QByteArray::fromRawData(mydata, sizeof(mydata));
    return byte;
}


QString int_to_QString(int i){
    QString str;
    str.append(QString("%1").arg(i));
    return str;
}

#endif // CONVERSION_GENERATION_FUNCTIONS_H
