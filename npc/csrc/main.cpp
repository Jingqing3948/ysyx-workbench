#include <stdio.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <nvboard.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* dut);

int main(int argc, char** argv) {
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	Vtop* top = new Vtop;
	VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
	top->trace(tfp, 0); //
	tfp->open("wave.vcd"); //设置输出的文件wave.vcd
	nvboard_bind_all_pins(&dut);  //绑定引脚
 	nvboard_init();         //开发板初始化
	int a=0,b=0;
	while (true) {
		// int a = rand() & 1;
		// int b = rand() & 1;
		// top->a = a;
		// top->b = b;
		// top->eval();
		// printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		
		// tfp->dump(contextp->time()); //dump wave
    	// contextp->timeInc(1); //推动仿真时间
		dut.eval();
		nvboard_update();    //更新NVBoard各组件状态
	}
	top->final();
	tfp->close();
	delete top;
	nvboard_quit();        //退出NVBoard
	return 0;
}