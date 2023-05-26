
public class Student extends User {
	private float grades[] = new float[3];
	private float finalGrade;
	private boolean approved;
	
	// Approved methods
	public void setApproved() {
		if(this.finalGrade >= 7) {
			this.approved = true;
		} else {
			this.approved = false;
		}	
	}
	// If approved = true, will return a string "Aprovado"(Approved), if approved = false, returns "Reprovado"(disapproved)
	public String getApproved() {
		if(this.approved == true) {
			return "Aprovado";
		} else {
			return "Reprovado";
		}
	}
	
	public void setGrades(int i, float grade) {
		this.grades[i] = grade;
	}
	public float getGrades(int i) {
		return this.grades[i];
	}
	
	// Final grade methods
	// Soma os valores das notas do array "grades" e, na variável private finalGrade, registra o valor da soma/3;
	// Sums all the values from array "grades" and, in the privade variable finalGrade, registrers the sum value/3
	public void setFinalGrade() {
		float finalGrade = 0;
		for(int i = 0; i < 3; i++){
			finalGrade = finalGrade + this.grades[i];
		}
		this.finalGrade = finalGrade/3;
	}
	public float getFinalGrade() {
		return this.finalGrade;
	}
	
	
	public void displayInfo() {
		System.out.println("Nome: " + getName());
		System.out.println("ID: " + getId());
		System.out.println("Email: " + getEmail());
		System.out.println("Media: " + getFinalGrade());
		System.out.println("Resultado: " + getApproved());
	}
	
	
	
}
