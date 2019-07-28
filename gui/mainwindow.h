#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtDebug>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_button_clicked();

    void on_save_button_clicked();

    void on_restart_button_clicked();

    void on_stop_button_clicked();

    void on_init_button_clicked();

    void on_uploadbutton_clicked();

    void on_delete_button_clicked();

private:
    Ui::MainWindow *ui;

    //File paths for all the files that will be manipulated
    QString reward_func_path =  "../docker/volumes/minio/bucket/custom_files/reward.py";
    QString action_space_path =  "../docker/volumes/minio/bucket/custom_files/model_metadata.json";
    QString hyperparameters_path =  "../rl_deepracer_coach_robomaker.py";
    QString track_path = "../docker/.env";

    //Will be read in on application start
    QString current_reward_func = "";
    QString current_action_space = "";
    QString current_hyperparameters = "";
    QString current_track = "";

    //List of all editable hyperparameters
    QStringList hyperparams{"batch_size","num_epochs","stack_size","lr","exploration_type","e_greedy_value","epsilon_steps",
                            "beta_entropy","discount_factor","loss_type","num_episodes_between_training","term_cond_max_episodes",
                            "term_cond_avg_score"};
    //Script Paths
    QString init_script =  "../init.sh";
    QString start_script =  "../scripts/training/start.sh";
    QString stop_script =  "../scripts/training/stop.sh";
    QString use_pretrained_script = "../scripts/training/set-last-run-to-pretrained.sh";
    QString upload_script = "../scripts/training/upload-snapshot.sh";
    QString delete_script = "../scripts/training/delete-last-run.sh";

    //General status variables
    bool is_running = false;
    bool is_pretrained = false;
};

#endif // MAINWINDOW_H