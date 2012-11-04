
int calcular_error_absoluto_porcentaje()
{   aux_errorLeido=dire - REFERENCIA;//calcula el error

    if (aux_errorLeido<0)               //
        aux_errorLeido=-aux_errorLeido; //  \\ calacula el
    else                                //  //  valor absoluto
        aux_errorLeido=aux_errorLeido;  // //
    porcentaje=BIAS_porc/((tanto_por_diento*(aux_errorLeido)+1));//calcula bias en funcion del error

    return(porcentaje);
}
