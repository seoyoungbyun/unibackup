package lab4;

public class Appointment {
    private int deptNo;
    private int newMgrNo;
    private double commission;
    
    public Appointment() {}

    public Appointment(int deptNo, int newMgrNo, double commission) {
        super();
        this.deptNo = deptNo;
        this.newMgrNo = newMgrNo;
        this.commission = commission;
    }

    public int getDeptNo() {
        return deptNo;
    }

    public void setDeptNo(int deptNo) {
        this.deptNo = deptNo;
    }

    public int getNewMgrNo() {
        return newMgrNo;
    }

    public void setNewMgrNo(int newMgrNo) {
        this.newMgrNo = newMgrNo;
    }

    public double getCommission() {
        return commission;
    }

    public void setCommission(double commission) {
        this.commission = commission;
    }
    
    
}
