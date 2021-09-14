//---------------------------------------------------------------------------
// Ishimoku indicator
//---------------------------------------------------------------------------

#include <windows.h>
#include <math.h>
#include "IndicatorInterfaceUnit.h"
#include "TechnicalFunctions.h"


// External variables
//PChar Currency = NULL;

// Buffers
//TIndexBuffer TenkanSen, KijunSen, ChinkouSpan, SenkouSpanA, SenkouSpanB;

char name_p[256];
char name_n[256];
char text[256];
char str_count[256];
int i;
int digits;
double price;
int iAdjPips2Price;

TIndexBuffer UpperLine, LowerLine;

//---------------------------------------------------------------------------
double PipsToPrice(double pips)
{
    price = 0;
    price = 10 * pips / pow(10, digits);

    if (digits == 3 || digits == 5) {

        price = 10 * pips / pow(10,digits);
        //MyPoint=Point*10;
    }
    if (digits == 2 || digits == 4) {
        price = pips / pow(10, digits);
        //MyPoint=Point*10;
    }

    price = price * pow(10, iAdjPips2Price);

    return(price);
}

//---------------------------------------------------------------------------
// Initialize indicator
//---------------------------------------------------------------------------
EXPORT void __stdcall Init()
{
  // define properties
  IndicatorShortName("Pips_Ruler_YA");
  SetOutputWindow(ow_ChartWindow);

  // register options
  AddSeparator("Common");

  RegOption("AdjPips2Price", ot_Integer, &iAdjPips2Price);
  SetOptionRange("AdjPips2Price", -10, +10);
  iAdjPips2Price = 0;

  digits = Digits();

  //UpperLine = CreateIndexBuffer();
  //LowerLine = CreateIndexBuffer();

  //IndicatorBuffers(2);
  //SetIndexBuffer(0, UpperLine);
  //SetIndexBuffer(1, LowerLine);

  //SetIndexStyle(0, ds_Line, psSolid, 2, clGreen);
  //SetIndexLabel(0, "Upper 10 Pips");
  //SetIndexStyle(1, ds_Line, psSolid, 2, clGreen);
  //SetIndexLabel(1, "Lower 10 Pips");

  ObjectDelete("Pips_Ruler_YA0");
  ObjectCreate("Pips_Ruler_YA0", obj_Text, 0, Time(0), Close(0));
  ObjectSetText("Pips_Ruler_YA0", "    - 0", 8, "Segoe UI Semibold", clDimGray);
  ObjectSet("Pips_Ruler_YA0", OBJPROP_VALIGNMENT, tlCenter);
  ObjectSet("Pips_Ruler_YA0", OBJPROP_HALIGNMENT, taLeftJustify);


  ObjectDelete("Pips_Ruler_YAp");
  //ObjectCreate(name_p, obj_Text, 0, Time(0), Close(0)+PipsToPrice(20));
  ObjectCreate("Pips_Ruler_YAp", obj_Text, 0, Time(0), Close(0) + PipsToPrice(20));
  ObjectSetText("Pips_Ruler_YAp", "    - 20", 8, "Segoe UI Semibold", clDimGray);
  ObjectSet("Pips_Ruler_YAp", OBJPROP_VALIGNMENT, tlCenter);
  ObjectSet("Pips_Ruler_YAp", OBJPROP_HALIGNMENT, taLeftJustify);

  ObjectDelete("Pips_Ruler_YAn");
  //ObjectCreate(name_p, obj_Text, 0, Time(0), Close(0)+PipsToPrice(20));
  ObjectCreate("Pips_Ruler_YAn", obj_Text, 0, Time(0), Close(0) - PipsToPrice(20));
  //sprintf_s(text, 255, "    - %d", 20);
  ObjectSetText("Pips_Ruler_YAn", "    - 20", 8, "Segoe UI Semibold", clDimGray);
  ObjectSet("Pips_Ruler_YAn", OBJPROP_VALIGNMENT, tlCenter);
  ObjectSet("Pips_Ruler_YAn", OBJPROP_HALIGNMENT, taLeftJustify);

  //Print("digits=" + digits);
  // register options
  //AddSeparator("Common");

  //ObjectCreate("Pips_Ruler_YA_01", obj_Text, 0, Time(0), Close(0));
  //ObjectSetText("Pips_Ruler_YA_01", "     - Test text", 8, "Segoe UI Semibold", clDimGray);
  //ObjectSet("Pips_Ruler_YA_01", OBJPROP_VALIGNMENT, tlBottom);
  //ObjectSet("Pips_Ruler_YA_01", OBJPROP_VALIGNMENT, tlCenter);
  //ObjectSet("Pips_Ruler_YA_01", OBJPROP_HALIGNMENT, taLeftJustify);
}
//---------------------------------------------------------------------------
EXPORT void __stdcall OnParamsChange()
{
}

//---------------------------------------------------------------------------
// Deinitialize indicator
//---------------------------------------------------------------------------
EXPORT void __stdcall Done()
{
  //free(Currency);

    strcpy_s(name_p, 255, "Pips_Ruler_YA");
    strcat_s(name_p, 255, "p");
    ObjectDelete(name_p);

    strcpy_s(name_n, 255, "Pips_Ruler_YA");
    strcat_s(name_n, 255, "n");
    ObjectDelete(name_n);

    if (0) {
        for (i = 1; i <= 20; i++) {
            strcpy_s(name_p, 255, "Pips_Ruler_YA");
            strcpy_s(name_n, 255, "Pips_Ruler_YA");
            sprintf_s(str_count, 255, "_%d", i);
            sprintf_s(text, 255, "    - %d", i);
            strcat_s(name_p, 255, str_count);
            strcat_s(name_n, 255, str_count);
            strcat_s(name_p, 255, "p");
            strcat_s(name_n, 255, "n");

            ObjectDelete(name_p);
            ObjectDelete(name_n);
        }
    }
}
//---------------------------------------------------------------------------
// Calculate requested bar
//---------------------------------------------------------------------------
EXPORT void __stdcall Calculate(int index)
{
    if (0 < index) {
        return;
    }

    if (!ObjectExists("Pips_Ruler_YA0")) {
        ObjectCreate("Pips_Ruler_YA0", obj_Text, 0, Time(0), Close(0));
        ObjectSetText("Pips_Ruler_YA0", "    - 0", 8, "Segoe UI Semibold", clDimGray);
        ObjectSet("Pips_Ruler_YA0", OBJPROP_VALIGNMENT, tlCenter);
        ObjectSet("Pips_Ruler_YA0", OBJPROP_HALIGNMENT, taLeftJustify);
    }

    //strcpy_s(name_p, 255, "Pips_Ruler_YA");
    //strcat_s(name_p, 255, "p");
    //ObjectDelete(name_p);
    //sprintf_s(text, 255, "    - %d", 20);
    //ObjectMove("Pips_Ruler_YA0", 0, Time(0), Close(0));
    if (1) {
        ObjectSet("Pips_Ruler_YA0", OBJPROP_TIME1, Time(0));
        ObjectSet("Pips_Ruler_YA0", OBJPROP_PRICE1, Close(0));
    }
    //ObjectMove("Pips_Ruler_YAp", 0, Time(0), Close(0) + PipsToPrice(20));
    if (!ObjectExists("Pips_Ruler_YAp")) {
        //ObjectCreate(name_p, obj_Text, 0, Time(0), Close(0)+PipsToPrice(20));
        ObjectCreate("Pips_Ruler_YAp", obj_Text, 0, Time(0), Close(0) + PipsToPrice(20));
        ObjectSetText("Pips_Ruler_YAp", "    - 20", 8, "Segoe UI Semibold", clDimGray);
        ObjectSet("Pips_Ruler_YAp", OBJPROP_VALIGNMENT, tlCenter);
        ObjectSet("Pips_Ruler_YAp", OBJPROP_HALIGNMENT, taLeftJustify);
    }

    if(1){
    ObjectSet("Pips_Ruler_YAp", OBJPROP_TIME1, Time(0));
    ObjectSet("Pips_Ruler_YAp", OBJPROP_PRICE1, Close(0) + PipsToPrice(20));
    }

    if (!ObjectExists("Pips_Ruler_YAn")) {
        ObjectCreate("Pips_Ruler_YAn", obj_Text, 0, Time(0), Close(0) - PipsToPrice(20));
        //sprintf_s(text, 255, "    - %d", 20);
        ObjectSetText("Pips_Ruler_YAn", "    - 20", 8, "Segoe UI Semibold", clDimGray);
        ObjectSet("Pips_Ruler_YAn", OBJPROP_VALIGNMENT, tlCenter);
        ObjectSet("Pips_Ruler_YAn", OBJPROP_HALIGNMENT, taLeftJustify);
    }
    //ObjectMove("Pips_Ruler_YAn", 0, Time(0), Close(0) - PipsToPrice(20));

    if(1){
    ObjectSet("Pips_Ruler_YAn", OBJPROP_TIME1, Time(0));
    ObjectSet("Pips_Ruler_YAn", OBJPROP_PRICE1, Close(0) - PipsToPrice(20));
    }

    if (0) {
        for (i = 1; i <= 2; i++) {
            strcpy_s(name_p, 255, "Pips_Ruler_YA");
            strcpy_s(name_n, 255, "Pips_Ruler_YA");
            sprintf_s(str_count, 255, "_%d", i);
            sprintf_s(text, 255, "    - %d", i);
            strcat_s(name_p, 255, str_count);
            strcat_s(name_n, 255, str_count);
            strcat_s(name_p, 255, "p");
            strcat_s(name_n, 255, "n");

            ObjectDelete(name_p);
            ObjectCreate(name_p, obj_Text, 0, Time(0), Close(0) + PipsToPrice(i * 20));
            ObjectSetText(name_p, text, 8, "Segoe UI Semibold", clDimGray);
            ObjectSet(name_p, OBJPROP_VALIGNMENT, tlCenter);
            ObjectSet(name_p, OBJPROP_HALIGNMENT, taLeftJustify);

            ObjectDelete(name_n);
            ObjectCreate(name_n, obj_Text, 0, Time(0), Close(0) - PipsToPrice(i * 20));
            ObjectSetText(name_n, text, 8, "Segoe UI Semibold", clDimGray);
            ObjectSet(name_n, OBJPROP_VALIGNMENT, tlCenter);
            ObjectSet(name_n, OBJPROP_HALIGNMENT, taLeftJustify);
        }
        //if (strcmp(Currency, Symbol()) != 0) return;
    }
}
