public class Main {
}

class Spreadsheet {
    private int[][] sheet;

    public Spreadsheet(int rows) {
        sheet = new int[rows + 1][26];
    }

    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.valueOf(cell.substring(1));
        sheet[row][col] = value;
    }

    public void resetCell(String cell) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.valueOf(cell.substring(1));
        sheet[row][col] = 0;
    }

    public int getValue(String formula) {
        formula = formula.substring(1);
        String[] opts = formula.split("\\+");
        int ans = 0;
        for (String opt : opts) {
            if (opt.matches("\\d+")) {
                ans += Integer.valueOf(opt);
            } else {
                int col = opt.charAt(0) - 'A';
                int row = Integer.valueOf(opt.substring(1));
                ans += sheet[row][col];
            }
        }
        return ans;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */