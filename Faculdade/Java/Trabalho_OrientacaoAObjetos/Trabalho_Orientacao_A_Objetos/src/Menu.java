public class Menu {
	
	public void displayMenu() {
		System.out.println("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		System.out.println("Digite\n1 para visualizar os dados de todos os alunos.\n2 para alterar o email de um aluno\n3 para alterar as notas de um aluno\n4 para encerrar o programa");
	}
	
	
	public void displayAllStudents(int size, Student[] students) {
		for(int i = 0; i < size; i++){
			students[i].displayInfo();
			System.out.print('\n');
		}
	}
	
	
	
	
	// Mudar o valor dos dados relacionados aos alunos
	public void alterStudentEmail(Student[] students, int choice, String value) {
		System.out.println("Email anterior: " + students[choice].getEmail());
		students[choice].setEmail(value);
		System.out.println("Email novo: " + value);
	}
	
	public void alterStudentGrades(Student[] students, int studentChoice, int gradeChoice, float value) {
		students[studentChoice].setGrades(gradeChoice, value);
	}
}
