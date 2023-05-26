public class Professor extends User {
	private String login;
	private String password;
	
	// Method to register a student grade
	// Input para enviar um valor que vai ser registrado na variável grades da classe Students
	public float RegisterGrades(float grade) {
		return grade;
	}
	
	// abaixo disso é tudo set e get simples, nada demais para comentar
	// Login related
	public void setLogin(String login) {
		this.login = login;
	}
	public String getLogin() {
		return this.login;
	}
	
	// Password related
	public void setPassword(String password) {
		this.password = password;
	}
	public String getPassword() {
		return this.password;
	}
}
