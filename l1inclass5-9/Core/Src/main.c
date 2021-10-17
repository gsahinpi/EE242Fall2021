
#define RCC  *((int *)0x40023830)
#define  GPIODMODER   *((int *) 0x40020c00)
#define GPIODODR *((int *)0x40020c14)
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)   /*!< 0x00000008 */
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk
#define GPIODMODERpin14set      1<<28
#define GPIODMODERpin15set      1<<30
#define GPIODodrpin14set        1<<14

#define GPIODodrpin15set        1<<15
int count=0;
//now gpio
/*
 * #define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
 * #define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
 * see rm0090 pg 65:
 * 0x4002 0C00 - 0x4002 0FFF GPIOD
 * #define GPIO_MODER_MODER14_Pos           (28U)

#define GPIO_ODR_OD14_Pos                (14U)
#define GPIO_ODR_OD14_Msk                (0x1UL << GPIO_ODR_OD14_Pos)
#define GPIO_ODR_OD14

 */
#define  GPIOD ((GPIO_TypeDef *)0x40020C00)
int main()
{
//*((int *)(0x20000020U))=0xfeddbacf;

RCC=  RCC_AHB1ENR_GPIODEN_Msk ;  //4U;
GPIODMODER=GPIODMODERpin15set; //GPIODMODERpin14set ;
GPIODMODER=GPIODMODER|GPIODMODERpin14set;

GPIODODR = GPIODodrpin14set  ;
GPIODODR |= GPIODodrpin15set ;//GPIODODR =GPIODODR|GPIODodrpin15set ;
GPIODODR=GPIODODR  &(~ (GPIODodrpin15set));

//*((int *)0x40020c14)=0x1U;

return 0;

}
