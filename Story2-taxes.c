#include "Story2.h"

/********************* Tax Methods **********************/


/*   Set tax rates by default   */
struct taxes rates(void){
	struct taxes t;
	t.ir = 0.15;
	t.pis = 0.0065;
	t.cofins = 0.03;
	t.csll = 0.09;
	return t;
};


/* This method calculates the assumed profit and the govern taxes to be paid */
struct withhold_taxes calculate(struct invoice i,struct taxes t)
{
	struct withhold_taxes wt;

	/* Calculation Logic to IR Tax */
	if(i.invoice_amount * t.ir > 10){
		wt.ir_withhold_tax_rate = i.invoice_amount * t.ir;
		wt.govern_amount = wt.ir_withhold_tax_rate;
	}
	
	/* Calculation Logic to Govern Taxes (PIS, COFINS and CSLL) and Assumed Profit */
	if(i.invoice_amount > 5000){
		wt.pis_withhold_tax_rate 	= i.invoice_amount * t.pis;
		wt.cofins_withhold_tax_rate = i.invoice_amount * t.cofins;
		wt.csll_withhold_tax_rate	= i.invoice_amount * t.csll;
		
		wt.govern_amount = wt.ir_withhold_tax_rate + wt.pis_withhold_tax_rate
		+ wt.cofins_withhold_tax_rate + wt.csll_withhold_tax_rate;
	}

	wt.assumed_profit = i.invoice_amount - wt.govern_amount;
	return wt;
}





