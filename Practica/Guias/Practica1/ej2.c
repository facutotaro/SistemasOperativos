void Ke_context_switch(struct PCB* pcb_0, struct PCB* pcb_1){
    pcb_0->STAT = KE_READY; //Ponemos al proceso como ready ya que no termino su ejecución
    pcb_0->CPU_TIME = ke_current_user_time(); //Asigna el tiempo que se ejecutó el proceso la ultima vez
    pcb_0->RO = R0; //Asignamos el valor actual en los registros del PCB
    pcb_1->STAT=KE_RUNNING; //Al nuevo proceso lo ponemos como ejecutandose
    R0 = pcb_1->RO; //En los registros asignamos el valor que tienen asignados en el nuevo PCB
    //Lo hacemos con todos
    R15 = pcb_1->R15;
    set_current_process(pcb_1->P_ID); //Asignamos al proceso con el PID del proximo a ejecutarse
    ke_reset_current_user_time(); //Reseteamos el timer
    ret(); //Desapila el tope de la pila y reemplaza el pc por el del nuevo pcb
}