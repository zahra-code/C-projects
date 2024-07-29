#include <stdio.h>
#include <string.h>
#define max_size 10000
#define max_items 100
#define max_ItemLength 100
#define MAX_NOTES 100
#define MAX_NOTE_LENGTH 256

// Structure for recipes
typedef struct {
    char name[100];
    int calories;
    char ingredients[max_size];
    char instructions[10][max_size];  // Adjust size as needed
} recipe;

// Global arrays for different categories
recipe italian[10];
recipe desi[10];
recipe drinks[10];
recipe edit[10];

// Function prototypes
void add_object(recipe *r, int index);
void print_add(recipe *r, int index);
void user_newrecipes();
//function for printing recipes
void print_object(recipe *r, int index);
//function for displaying recipes
void display_recipe();
//function for adding notes 
void addNotes();
//function for creating shopping list
void shoping_list();
//function for rating the recipe book
void rating();
//function for recommending recipes according to time
void recommendRecipebyTime();
//function for recommending recipes according to season
void recommendRecipebySeason();
//our main menu
void menu();

int main() {
	//making objects:
    //breakfast
    //item1
	strcpy(italian[0].name, "Frittata");
	italian[0].calories = 200;
	strcpy(italian[0].ingredients,"6 eggs (~420 calories)\n1/2 cup milk (~60 calories)\n1 cup diced vegetables (e.g., bell peppers, onions, spinach) (~50 calories)\n2 cup shredded cheese (~200 calories)\nSalt and pepper to taste\n2 tbsp olive oil (~240 calories)\n");
	strcpy(italian[0].instructions[0],"Preheat the oven to 350°F (175°C).\nIn a bowl, whisk together the eggs, milk, salt, and pepper.\nHeat the olive oil in an oven-safe skillet over medium heat.\nAdd the vegetables and sauté until tender.\nPour the egg mixture over the vegetables and cook for 2-3 minutes.\nSprinkle the cheese on top and transfer the skillet to the oven.\nBake for 10-12 minutes, or until the eggs are set.\nServe warm.\n");
	//item2
	strcpy(italian[1].name,"Croissant with Jam");
	italian[1].calories=260;
	strcpy(italian[1].ingredients,"1 croissant (~230 calories)\n1 tbsp jam (~30 calories)\n");
	strcpy(italian[1].instructions[0],"Slice the croissant in half.\nSpread the jam on one half.\nServe immediately.\n");
	//lunch items
	//item1
	strcpy(italian[2].name,"Caprese Salad");
	italian[2].calories=250;
	strcpy(italian[2].ingredients,"2 large tomatoes, sliced (~40 calories)\n1 ball fresh mozzarella, sliced (~320 calories)\nFresh basil leaves (negligible calories)\n2 tbsp balsamic vinegar (~20 calories)\n2 tbsp olive oil (~240 calories)\nSalt and pepper to taste\n");
	strcpy(italian[2].instructions[0],"Arrange the tomato and mozzarella slices alternately on a plate.\nScatte fresh basil leaves over the top.\nDrizzle with balsamic vinegar and olive oil.\nSeason with salt and pepper.\nServe immediately.\n");
	//item2
	strcpy(italian[3].name,"Margherita Pizza");
	italian[3].calories=350;
	strcpy(italian[3].ingredients,"Pizza dough (~600 calories)\n1/2 cup tomato sauce (~40 calories)\n1 cup fresh mozzarella, sliced (~320 calories)\nFresh basil leaves (negligible calories)\n1 tbsp olive oil (~120 calories)\nSalt and pepper to taste\n");
	strcpy(italian[3].instructions[0],"Preheat the oven to 475°F (245°C).\nRoll out the pizza dough on a floured surface.\nSpread the tomato sauce over the dough.\nArrange the mozzarella slices on top.\nDrizzle with olive oil and season with salt and pepper.\nBake for 10-12 minutes, or until the crust is golden and the cheese is bubbly.\nTop with fresh basil leaves before serving.\n");
	//dinner
	//item1
	strcpy(italian[4].name,"Spaghetti Carbonara");
	italian[4].calories=500;
	strcpy(italian[4].ingredients,"12 oz spaghetti (~1200 calories)\n4 oz pancetta or bacon, diced (~600 calories)\n2 large eggs (~140 calories)\n1 cup grated Parmesan cheese (~430 calories)\nSalt and pepper to taste\n2 cloves garlic, minced (~10 calories)\n2 tbsp olive oil (~240 calories)\n");
	strcpy(italian[4].instructions[0],"Cook the spaghetti according to package instructions.\nIn a large skillet, heat the olive oil over medium heat.\nAdd the pancetta or bacon and cook until crispy.\nAdd the garlic and sauté for 1 minute.\nIn a bowl, whisk together the eggs and Parmesan cheese.\nDrain the spaghetti and add it to the skillet.\nRemove the skillet from the heat and quickly stir in the egg and cheese mixture.\nSeason with salt and pepper and serve immediately.\n");
	//item2
	strcpy(italian[5].name,"Chicken Parmesan");
	italian[5].calories=450;
	strcpy(italian[5].ingredients,"4 chicken breasts (~800 calories)\n1 cup bread crumbs (~400 calories)\n1 cup grated Parmesan cheese (~430 calories)\n1 egg (~70 calories)\n2 cups marinara sauce (~240 calories)\n1 cup shredded mozzarella cheese (~320 calories)\nSalt and pepper to taste\n2 tbsp olive oil (~240 calories)\n");
	strcpy(italian[5].instructions[0],"Preheat the oven to 375°F (190°C).\nPound the chicken breasts to an even thickness.\nIn one bowl, beat the egg. In another bowl, mix the bread crumbs and half of the Parmesan cheese.\nDip each chicken breast in the egg, then coat with the bread crumb mixture.\nHeat the olive oil in a skillet over medium heat and cook the chicken until golden brown on both sides.\nPlace the chicken in a baking dish. Pour marinara sauce over the top, then sprinkle with mozzarella and the remaining Parmesan cheese.\nBake for 20-25 minutes, or until the cheese is melted and bubbly.\nServe hot.\n");
    //snacks
    //item1
    strcpy(italian[6].name,"Bruschetta");
	italian[6].calories=90;
	strcpy(italian[6].ingredients,"1 baguette, sliced (~1200 calories)\n2 cups diced tomatoes (~40 calories)\n1/4 cup chopped fresh basil (negligible calories)\n2 cloves garlic, minced (~10 calories)\n2 tbsp olive oil (~240 calories)\nSalt and pepper to taste\n");
	strcpy(italian[6].instructions[0],"Preheat the oven to 400°F (200°C).\nArrange the baguette slices on a baking sheet and drizzle with olive oil.\nBake for 5-7 minutes, or until golden and crispy.\nIn a bowl, combine the tomatoes, basil, garlic, olive oil, salt, and pepper.\nSpoon the tomato mixture onto the toasted baguette slices and serve.\n");
	//item2
    strcpy(italian[7].name,"Caprese Skewers");
	italian[7].calories=80;
	strcpy(italian[7].ingredients,"Cherry tomatoes (~15 calories per 10 tomatoes)\nFresh mozzarella balls (~70 calories per 10 small balls)\nFresh basil leaves (negligible calories)\n1 tbsp balsamic glaze (~20 calories)\n1 tbsp olive oil (~120 calories)\nSalt and pepper to taste\n");
	strcpy(italian[7].instructions[0],"On each skewer, thread cherry tomatoes, mozzarella balls, and basil leaves.\nDrizzle with balsamic glaze and olive oil.\nSeason with salt and pepper.\nServe immediately.\n");
    //desi object 
    //breakfast
	//item1
    strcpy(desi[0].name,"Aloo Paratha");
	desi[0].calories=300;
	strcpy(desi[0].ingredients,"2 cups whole wheat flour (~800 calories)\n1 cup water (negligible calories)\n2 large potatoes, boiled and mashed (~320 calories)\n1/2 cup chopped onions (~20 calories)\n2 green chilies, finely chopped (negligible calories)\n1 tsp cumin seeds (negligible calories)\n1 tsp garam masala (negligible calories)\nSalt to taste\nGhee or oil for cooking (~240 calories for 2 tbsp)\n");
	strcpy(desi[0].instructions[0],"Knead the flour and water into a smooth dough and set aside.\nIn a bowl, mix the mashed potatoes, onions, green chilies, cumin seeds, garam masala, and salt.\nDivide the dough into small balls and roll them out into circles.\nPlace a spoonful of the potato mixture in the center of each circle.\nFold the edges over the filling and roll out again into a flatbread.\nHeat a skillet over medium heat and cook the paratha with ghee or oil until golden on both sides.\nServe hot with yogurt or pickle.\n");
	//item2
    strcpy(desi[1].name,"Chana Chaat");
	desi[1].calories=200;
	strcpy(desi[1].ingredients,"2 cups boiled chickpeas (~480 calories)\n1/2 cup chopped onions (~20 calories)\n1/2 cup chopped tomatoes (~20 calories)\n1/4 cup chopped cilantro (negligible calories)\n1 green chili, chopped (negligible calories)\n1 tsp chaat masala (negligible calories)\n2 tbsp tamarind chutney (~40 calories)\nSalt to taste\n");
	strcpy(desi[1].instructions[0],"In a bowl, mix the boiled chickpeas, onions, tomatoes, cilantro, and green chili.\n\nAdd chaat masala, tamarind chutney, and salt.\nToss well and serve immediately.\n");
//lunch
	//item1
    strcpy(desi[2].name,"Biryani");
	desi[2].calories=450;
	strcpy(desi[2].ingredients,"2 cups basmati rice (~1300 calories)\n1 lb chicken, cut into pieces (~800 calories)\n2 onions, sliced (~80 calories)\n2 tomatoes, chopped (~40 calories)\n1 cup yogurt (~150 calories)\n2 tbsp biryani masala (~20 calories)\n1 tsp turmeric (negligible calories)\n1 tsp red chili powder (negligible calories)\n1/2 cup chopped cilantro and mint (negligible calories)\n4 cups water (negligible calories)\n2 tbsp ghee or oil (~240 calories)\nSalt to taste\n");
	strcpy(desi[2].instructions[0],"Cook the rice in 4 cups of water until 70% done and set aside.\nHeat ghee or oil in a large pot and sauté the onions until golden brown.\nAdd the chicken and cook until no longer pink.\nAdd the tomatoes, yogurt, biryani masala, turmeric, red chili powder, and salt.\nCook until the chicken is fully cooked and the gravy thickens.\nLayer the partially cooked rice over the chicken mixture.\nTop with cilantro and mint.\nCover and cook on low heat for 20 minutes.\nServe hot.\n");
	//dinner
	//item1
    strcpy(desi[3].name,"Palak Paneer");
	desi[3].calories=300;
	strcpy(desi[3].ingredients,"1 lb spinach, washed and chopped (~65 calories)\n8 oz paneer, cubed (~700 calories)\n1 onion, chopped (~40 calories)\n2 tomatoes, chopped (~40 calories)\n2 green chilies, chopped (negligible calories)\n1 tbsp ginger-garlic paste (~15 calories)\n1 tsp cumin seeds (negligible calories)\n1 tsp garam masala (negligible calories)\n1/2 cup cream (~200 calories)\n2 tbsp ghee or oil (~240 calories)\nSalt to taste");
	strcpy(desi[3].instructions[0],"Blanch the spinach in boiling water for 2 minutes, then puree it in a blender.\nHeat ghee or oil in a pan and sauté the cumin seeds.\nAdd the onions and cook until golden brown.\nAdd the ginger-garlic paste and green chilies and sauté for 2 minutes.\nAdd the tomatoes and cook until soft.\nStir in the spinach puree, garam masala, and salt.\nAdd the paneer cubes and simmer for 10 minutes.\nStir in the cream and cook for another 2 minutes.\nServe hot with naan or rice.\n");
//snacks
	//item1
    strcpy(desi[4].name,"Samosa");
	desi[4].calories=150;
	strcpy(desi[4].ingredients,"2 cups all-purpose flour (~800 calories)\n4 tbsp ghee or oil (~240 calories)\n1/2 cup water (negligible calories)\n2 large potatoes, boiled and mashed (~320 calories)\n1/2 cup green peas (~50 calories)\n1 tsp cumin seeds (negligible calories)\n1 tsp coriander powder (negligible calories)\n1 tsp garam masala (negligible calories)\n1 tsp red chili powder (negligible calories)\nSalt to taste\nOil for frying (~240 calories for 2 cups)\n");
	strcpy(desi[4].instructions[0],"In a bowl, mix the flour, ghee or oil, and salt.\nAdd water gradually to form a stiff dough and set aside.\nIn a pan, heat some oil and add the cumin seeds.\nAdd the potatoes, peas, coriander powder, garam masala, red chili powder, and salt.\nCook for a few minutes and let it cool.\nRoll out the dough into small circles and cut each circle in half.\nForm a cone with each half and fill it with the potato mixture.\nSeal the edges and deep-fry the samosas until golden brown.\nServe hot with chutney.\n");
//drinks

	//item1
    strcpy(drinks[0].name,"Chocolate Milk");
	drinks[0].calories=200;
	strcpy(drinks[0].ingredients,"1 cup milk (whole milk for ~150 calories, lower for skim or low-fat)\n2 tablespoons chocolate syrup (~50 calories)");
	strcpy(drinks[0].instructions[0],"Pour the milk into a glass.\nAdd the chocolate syrup.\nStir well until the syrup is fully mixed into the milk.\nServe chilled.\n");
	//item2
    strcpy(drinks[1].name,"Coffee");
	drinks[1].calories=74;
	strcpy(drinks[1].ingredients,"1 cup of freshly brewed coffee (~2 calories)\n1-2 teaspoons of sugar or sweetener (~16-32 calories, depending on the amount)\n1-2 tablespoons of cream or milk (~20-40 calories, depending on the amount)\nOptional: Flavorings such as vanilla extract, cinnamon, or chocolate syrup (calories vary)\n");
	strcpy(drinks[1].instructions[0],"Brew a cup of coffee using your preferred method (drip, French press, espresso, etc.).\nAdd sugar or sweetener to taste, stirring until dissolved.\nPour in cream or milk, again adjusting to your desired level of creaminess.\nIf using flavorings, add them according to your preference and stir well.\nTaste and adjust sweetness or creaminess if necessary.\nServe hot and enjoy!\n");
	//item3
    strcpy(drinks[2].name,"Lemon-Lime Soda");
	drinks[2].calories=100;
	strcpy(drinks[2].ingredients,"1 cup sparkling water (negligible calories)\n2 tablespoons simple syrup (~50 calories)\n1 tablespoon fresh lemon juice (~5 calories)\n1 tablespoon fresh lime juice (~5 calories)");
	strcpy(drinks[2].instructions[0],"Pour the sparkling water into a glass.\nAdd the simple syrup, lemon juice, and lime juice.\nStir gently until fully mixed.\nServe chilled with ice.\n");
	//item4
    strcpy(drinks[3].name," Homemade Cola");
	drinks[3].calories=150;
	strcpy(drinks[3].ingredients,"1 cup sparkling water (negligible calories)\n2-3 tablespoons cola syrup (~100-150 calories)\n");
	strcpy(drinks[3].instructions[0],"Pour the sparkling water into a glass.\nAdd the cola syrup.\nStir gently until fully mixed.\nServe chilled.\n");
	
  
   
    menu();
    return 0;
}

void add_object(recipe *r, int index) {
    int i;
    printf("Recipe name: ");
    fgets(r[index].name, sizeof(r[index].name), stdin);
    r[index].name[strcspn(r[index].name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter details of recipe (end with 'done'):\n");
    for (i = 0; i < 10; i++) {
        fgets(r[index].instructions[i], sizeof(r[index].instructions[i]), stdin);
        r[index].instructions[i][strcspn(r[index].instructions[i], "\n")] = '\0'; // Remove trailing newline
        if (strcmp(r[index].instructions[i], "done") == 0) {
            r[index].instructions[i][0] = '\0'; // Mark end of instructions
            break;
        }
    }
}

void print_add(recipe *r, int index) {
    int i;
    printf("\nRECIPE NAME: %s\n\n", r[index].name);
    printf("RECIPE DETAILS:\n\n");
    for (i = 0; i < 10 && r[index].instructions[i][0] != '\0'; i++) {
        printf("%s\n", r[index].instructions[i]);
    }
}

void user_newrecipes() {
    int i, amount;
    printf("\033[32m\n\t\t\t\t\tADD YOUR RECIPES\n\033[0m\n");
    printf("How many recipes do you want to add? ");
    scanf("%d", &amount);
    fflush(stdin);//clear garbage
    for (i = 0; i < amount; i++) {
    	printf("\033[33m\n\tEnter recipe %d\n\033[0m\n",i+1);
        add_object(edit, i);
    }

    for (i = 0; i < amount; i++) {
        printf("\033[33m\n\trecipe %d\n\033[0m\n",i+1);
        print_add(edit, i);
    }
}

void print_object(recipe *r, int index) {
	int i=0;
	printf("\033[33m\nRECIPE NAME:\033[0m%s\n",r[index].name);
	printf("\033[35m\nRECIPE CALORIES:\033[0mcalories per serving =%d calories\n", r[index].calories);
	printf("\033[35m\nRECIPE INGREDIENTS:\033[0m%s\n", r[index].ingredients);
	printf("\033[35m\nRECIPE INSTRUCTIONS:\033[0m\n");
    for (i = 0; i < 10 && r[index].instructions[i][0] != '\0'; i++) {
        printf("%s\n", r[index].instructions[i]);
    }
}

void display_recipe() {
    int choice, choice1;
    printf("\033[32m\n\t\t\t\t\t\tRECIPE MENU:\n\033[0m\n");
    printf("Select an option to continue:\n");
    printf("1. Breakfast\n");
    printf("2. Lunch\n");
    printf("3. Dinner\n");
    printf("4. Snacks\n");
    printf("5. Drinks\n");
    printf("6. EXIT\n");
    scanf("%d", &choice);
    fflush(stdin);

    switch (choice) {
        case 1:
        	printf("\033[33m\n\nCATEGORIES\n\033[0m\n");
            printf("1. Italian breakfast items\n");
            printf("2. Desi breakfast items\n");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                print_object(italian, 0);
                print_object(italian, 1);
            } else if (choice1 == 2) {
                print_object(desi, 0);
                print_object(desi, 1);
            }
            else{
            	printf("ENTER VALID CHOICE\n");
			}
            break;
        case 2:
            printf("\033[33m\n\nCATEGORIES\033[0m\n");
            printf("1. Italian lunch items\n");
            printf("2. Desi lunch items\n");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                print_object(italian, 2);
                print_object(italian, 3);
            } else if (choice1 == 2) {
                print_object(desi, 2);
            }
            else{
            	printf("ENTER VALID CHOICE\n");
			}
            break;
        case 3:
            printf("\033[33m\n\nCATEGORIES\033[0m\n");
            printf("1. Italian dinner items\n");
            printf("2. Desi dinner items\n");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                print_object(italian, 4);
                print_object(italian, 5);
            } else if (choice1 == 2) {
                print_object(desi, 3);
            }
            else{
            	printf("ENTER VALID CHOICE\n");
			}
            break;
        case 4:
            printf("\033[33m\n\nCATEGORIES\033[0m\n");
            printf("1. Italian snacks\n");
            printf("2. Desi snacks\n");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                print_object(italian, 6);
                print_object(italian, 7);
            } else if (choice1 == 2) {
                print_object(desi, 4);
            }
            else{
            	printf("ENTER VALID CHOICE\n");
			}
            break;
        case 5:
            printf("\033[33m\n\nCATEGORIES\033[0m\n");
            printf("1. Milk drinks\n");
            printf("2. Sodas\n");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                print_object(drinks, 0);
                print_object(drinks, 1);
            } else if (choice1 == 2) {
                print_object(drinks, 2);
                print_object(drinks, 3);
            }
            else{
            	printf("ENTER VALID CHOICE\n");
			}
            break;
        case 6:
            break;
        default:
            printf("\tENTER VALID CHOICE\n");
    }
}
void shoping_list()
{
	char shopingList[max_items][max_ItemLength];
	int numItems,i;
	printf("how many elements u want to enter in the list");
	scanf("%d",&numItems);
	getchar();
	if (max_items>max_items) {
	printf("The maximum number of items is %d. Please try again.\n",max_items);
	return;
	}
	for(i=0;i<numItems;i++){
		printf("enter the item no# %d= ",i+1);
		gets(shopingList[i]);
	}
	 // Display the shopping list
	 printf("\n");
	printf("\033[33mYour Shopping List\033[0m\n");
	for (i=0;i<numItems;i++) {
	printf("%d. %s\n", i + 1,shopingList[i]);
	}	
}
void addNotes(){
	char notes[MAX_NOTES][MAX_NOTE_LENGTH];
	int numnotes,i;
	printf("how many no.of notes u want to enter in the list");
	scanf("%d",&numnotes);
	getchar();
	if (numnotes>MAX_NOTES) {
	printf("The maximum number of notes is %d. Please try again.\n",MAX_NOTES);
	return;
	}
	for(i=0;i<numnotes;i++){
		printf("enter note %d= ",i+1);
		gets(notes[i]);
	}
	 // Display the notes
	printf("\n");
	printf("\033[33mYour notes are\033[0m\n");
	for (i=0;i<numnotes;i++) {
	printf("%d. %s\n", i + 1,notes[i]);
	}
	printf("notes added and displated");	
}
void rating(){

	float rating;
	printf("\033[33m\nRATING ^_^\033[0m\n");
	printf(" How was your experience with our recipe book?\n");
	printf("RATE BETWEEN 1-10\n");
	scanf("%f",&rating);
	if(rating>=8 && rating<=10)
	printf("THANK YOU!\nWE ARE PLEASED BY YOUR FEEDBACK\n");
	else if(rating>=5 && rating<=7)
	printf("WE ARE WORKING ON THE ISSUES!\n THANK YOU FOR YOUR FEEDBACK!\n");
	else
	printf("REALLY SORRY FOR THE ISSUES:(\n");
}
void recommendRecipebyTime()
{
	int timelimit;
	char choice;
	printf("\033[33m\n RECOMMENDATIONS\033[0m\n");
	printf("WE WILL DISPLAY YOU OUR RECOMMENDATIONS BY CONSIDERING TIME LIMIT:\n");
	printf("PRESS 1 for 10 min\n");
	printf("PRESS 2 for 30 min\n");
	printf("PRESS 3 for 60 min\n");
	printf("PRESS 4 for 120 min\n");
	scanf("%d",&timelimit);
	switch(timelimit){
	case 1:
	    printf("We have following options:\n");
	    printf(" >Croissant with Jam\n");
	    printf(" >Caprese Salad\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	    print_object(italian,1);
	    print_object(italian,2);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	case 2:
	    printf("We have following options:\n");
	    printf(" >Spaghetti Carbonara\n");
	    printf(" >Chana Chaat\n");
	    printf(" >Aloo Paratha\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	         print_object(italian,4);
	         print_object(desi,1);
	         print_object(desi,0);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	case 3:
	    printf("We have following options:\n");
	    printf(" >Chicken Parmesan\n");
	    printf(" >Margherita Pizza\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	        print_object(italian,5);
	        print_object(italian,3);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	case 4:
	    printf("We have following options:\n");
	    printf(" >Biryani\n");
	    printf(" >Palak Paneer\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	        print_object(desi,2);
	        print_object(desi,3);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");  
	break;
	default:
		printf("\tenter valid choice!!\n");
}
}
void recommendRecipebySeason()
{
	int userchoice;
	char choice;
	printf("\033[33m\n RECOMMENDATIONS\033[0m\n");
	printf("\nWE WILL DISPLAY YOU OUR RECOMMENDATIONS FOR SEASONS:\n");
	printf("PRESS 1 for SUMMER\n");
	printf("PRESS 2 for WINTER\n");
	printf("PRESS 3 for RAINY SEASON\n");
	scanf("%d",&userchoice);
	switch(userchoice){
	case 1:
	    printf("We have following options:\n");
	    printf(" >LEMON LIME SODA\n");
	    printf(" >HOMEMADE COLAA\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	    print_object(drinks,2);
	    print_object(drinks,3);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	case 2:
	    printf("We have following options:\n");
	    printf(" >COFFEE\n");
	    printf(" >CHOCOLATE MILK\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	         print_object(drinks,0);
	         print_object(drinks,1);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	case 3:
	    printf("We have following options:\n");
	    printf(" >CHANNA CHAT\n");
	    printf(" >SAMOSA\n");
	    printf("Do you want to view the RECIPES(y/n):\n");
	    choice=getch();
	    if(choice=='y'){
	        print_object(desi,1);
	        print_object(desi,4);}
	   else
	   printf("OKAY NO PROBLEM! HOPE OUR RECOMMENDATIONS HELPED YOU!!");
	break;
	default:
		printf("\tenter valid choice!!\n");
}
}
void menu() {
    int choice;
    while (1) {
        printf("\033[31m\n\n\t\t\t\t\t\tDIGITAL RECIPE BOOK\n\n\033[0m\n");
        printf("Welcome to our digital recipe book, how can we help you? Choose an option to continue:\n");
        printf("1. Display recipes\n");
        printf("2. Get recommendation according to season\n");
        printf("3. Get recommendation according to time\n");
        printf("4. Add recipes manually\n");
        printf("5. Create shopping list\n");
        printf("6. Add notes\n");
        printf("7. Rating\n");
        printf("8. EXIT\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
            	//for clearing the console
            	system("cls");
                display_recipe();
                break;
            case 2:
            	system("cls");
            	recommendRecipebySeason();
            break;
            case 3:
            	system("cls");
            	recommendRecipebyTime();
            break;
            case 4:
            	system("cls");
                user_newrecipes();
                break;
            case 5:
            	system("cls");
                shoping_list();
            break;
            case 6:
            	system("cls");
                addNotes();
            break;
            case 7:
            	system("cls");
            	rating();
            break;
            case 8:
            	system("cls");
            	printf("\033[31m\n\t\t\t\t\tTHANKS FOR USING OUR RECIPE BOOK\n\033[0m\n");
                return;// Exit the program
            default:
            	system("cls");
                printf("\tEnter valid CHOICE\n");
        }
        
    }
}
