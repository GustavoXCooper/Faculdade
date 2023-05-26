import java.util.Scanner;

public class Main {
	public static void main(String[] arg) {
		// userChoice will be used in the user's choices
		int userChoice = 0;
		int studentsSize = 0;
		Scanner input = new Scanner(System.in);
		
		
		// Introduction screen
		IntroScreen intro = new IntroScreen();
		intro.Intro();
		
		// Creating professor account
		Professor professor = new Professor();
		professor.setName("Rubem Matimoto Koide");
		professor.setLogin("RubemMKoide");
		professor.setPassword("123");
		professor.setId("1000");
		
		
		// Login Screen
		LoginScreen loginScreen = new LoginScreen();
		while(loginScreen.getLogin() == false) {
			String login;
			String password;
			System.out.println("\nLogin:");
			login = input.nextLine();
			System.out.println("\nSenha:");
			password = input.nextLine();
			
			loginScreen.login(professor.getLogin(), professor.getPassword(), login, password);
		}
		
		
		// Registring all the students
		System.out.println("Quantos alunos deseja registrar?");
		studentsSize = input.nextInt();
		
		Student[] students = new Student[studentsSize];
		input.nextLine();
		
		for(int i = 0; i < studentsSize; i++) {
			String name;
			int idNumber;
			students[i] = new Student();
			
			System.out.println("Insira o nome do aluno " + (i+1) + ":");
			name = input.nextLine();
			students[i].setName(name);
			
			// Registring grades from students
			for(int j = 0; j < 3; j++) {
				float grade;
				System.out.println("Insira a nota " + (j+1) + ":");
				grade = input.nextFloat();
				
				students[i].setGrades(j, professor.RegisterGrades(grade));
				/* 
				English:
				Made a method in the Professor class to register all the grades.
				I don't know if that's the ideal way, but I thought it would be 
				interesting, so only when you have access to the class Professor's
				methods a grade can be given to an student
				
				Portuguese: 
				Fiz um método específico na classe Professor para registrar as notas. 
				Não sei se é a forma ideal, poderia só enviar o valor
				mas achei que seria interessante, assim somente quando se tem acesso as funções de 
				Professor se pode dar uma nota para um aluno
				*/
				input.nextLine();
			}
			students[i].setFinalGrade();
			students[i].setApproved();
			
			// Id is automatically registered, no need to type it in;
			idNumber = 1000 +  i + 1;
			students[i].setId(Integer.toString(idNumber));
			// Only visual
			for(int j = 0; j < 3; j++) {
				System.out.print('\n');
			}
		}
		
		Menu menu = new Menu();
		
		boolean displayMenu = true;
		while(displayMenu == true) {
			menu.displayMenu();
			userChoice = input.nextInt();
			input.nextLine();
			
			System.out.println("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
			switch(userChoice) {
			case 1:
				menu.displayAllStudents(studentsSize, students);
				break;
			case 2:
				System.out.println("Deseja alterar o email de qual aluno?\n");
				for(int i = 0; i < studentsSize; i++) {
					System.out.println(i + 1 + ". " + students[i].getName() + "\n");
				}
				
				userChoice = input.nextInt();
				input.nextLine();
				userChoice--;
				
				System.out.println("Insira o novo email: ");
				
				String valueString = input.nextLine();
				
				menu.alterStudentEmail(students, userChoice, valueString);
				break;
			case 3:
				System.out.println("Deseja alterar as notas de qual aluno?\n");
				for(int i = 0; i < studentsSize; i++) {
					System.out.println(i + 1 + ". " + students[i].getName() + "\n");
				}
				userChoice = input.nextInt();
				input.nextLine();
				userChoice--;
				float valueFloat;
				for(int i = 0; i < 3; i++) {
					System.out.println("Insira a nota " + (i + 1) + ":");
					valueFloat = input.nextFloat();
					input.nextLine();
					menu.alterStudentGrades(students, userChoice, i, valueFloat);
				}
				// Calculating again the final grade and if it's approved or not
				students[userChoice].setFinalGrade();
				students[userChoice].setApproved();
				break;
			case 4:
				System.out.println("\nOs dados finais dos alunos sao os seguintes:\n");
				menu.displayAllStudents(studentsSize, students);
				System.out.println("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
				System.out.println("\n\nObrigado, professor!");
				System.exit(0);
				break;
			default:
				System.out.println("Valor invalido. Tente novamente.");
			} 
		}
		
		input.close();
	}
}
