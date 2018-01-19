<template>
  <div class="content">
    <div id="bg">
      <img id="bg_pic" src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109034814567_11.png" />
      <div id="logoCotent">
        <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109034509455_36.png" />
      </div>
    </div>
    <div id="tips">
      <h6>电子公交卡</h6>
      <h5>请先授权开启浙江政务服务网电子公交卡业务</h5>
    </div>
    <button @click="authorize">确认授权</button>
  </div>
</template>

<script>
  export default {
    name: 'authorize',
    methods: {
      authorize () {
        console.log(23)
      }
    }
  }
</script>

<style scoped lang="scss">
  @import "../common/style/variable.scss";
  .content {
    @include fill-all;
    background: white;
    #bg {
      width: 100%;
      position: relative;

      #bg_pic {
        width:100%;
      }

      #logoCotent {
        width: 8rem;
        height: 8rem;
        background: white;
        position: absolute;
        bottom: -4rem;
        left: 50%;
        transform: translateX(-50%);
        border-radius: 10%;
        border: 1px solid #e8e6e6;
        box-shadow:0px 0px 2px #e8e6e6;
        text-align: center;
        line-height: 8rem;
        img {
          width: 80%;
        }
      }
    }
    #tips{
      margin-top: 6rem;
      text-align:center;
      font-size:1.6rem;
      h5 {
        color: #666;
        margin-top: 2rem;
      }
    }
    button {
      width: 90%;
      height: 7vh;
      border-radius: 0.5rem;
      font-size: 2rem;
      color: #fff;
      background-color: #1592ff;
      position: absolute;
      bottom: 4rem;
      left: 50%;
      transform: translateX(-50%);
    }
  }
</style>